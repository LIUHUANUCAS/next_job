package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"os"
	"os/signal"
	"syscall"
	"time"
)

type TaskIDType int

const (
	taskIDCtx TaskIDType = iota + 1
)

type TaskManager struct {
	taskGenerate Generate
	httpAPI      HttpAPI
	kafkaAPI     KafkaAPI
}

func sync(f func()) {
	for {
		f()
	}
}
func (tm *TaskManager) Start(ctx context.Context) {
	param := GenerateParam{
		TaskType: "db_task",
		TaskNum:  100,
	}
	tasks, err := tm.taskGenerate.Generate(ctx, param)
	if err != nil {
		return
	}
	log.Println("generated:", tasks)

	taskmap := make(map[string]*Task)
	deleteTask := make(map[string]struct{})
	for i, t := range tasks {
		log.Println("task config", i, t)
		if task, ok := taskmap[t.TaskID]; ok {
			task.Update(ctx, t)
		} else {
			newTask, err := NewTask(t, tm.httpAPI, tm.kafkaAPI)
			if err != nil {
				log.Println("new taskerr:", err)
				deleteTask[t.TaskID] = struct{}{}
				continue
			}
			log.Println("start task:", t)
			taskmap[t.TaskID] = newTask
			newCtx := context.WithValue(ctx, taskIDCtx, t.TaskID)
			go newTask.Start(newCtx)
		}
	}

	//stop task that stopped running

}

type Task struct {
	httpAPI  HttpAPI
	kafkaAPI KafkaAPI
}

func NewTask(cfg TaskConfig, httpAPI HttpAPI, kafkaAPI KafkaAPI) (*Task, error) {
	return &Task{httpAPI: httpAPI, kafkaAPI: kafkaAPI}, nil
}

func (t *Task) Start(ctx context.Context) {
	url := "localhost:8080"
	topic := "raw"
	f := func() {
		data, err := t.httpAPI.GetData(ctx, url)
		if err != nil {
			fmt.Println("err", err)
		}
		t.kafkaAPI.Produce(topic, KafkaItem{Data: data.Data})
	}
	for {
		select {
		case <-ctx.Done():
			return
		default:
			f()
			time.Sleep(time.Second * 3)
		}

	}
}

func (t *Task) Update(ctx context.Context, cfg TaskConfig) {

}

func NewTaskManager(g Generate, httpAPI HttpAPI, kafkaAPI KafkaAPI) *TaskManager {
	return &TaskManager{
		taskGenerate: g,
		httpAPI:      httpAPI,
		kafkaAPI:     kafkaAPI,
	}
}

// 1. generate tasks
// 2. task is get data from http API
// 3. make it to kafka, send it to kafka

type TaskConfig struct {
	TaskID string
}

type GenerateTask struct {
}

func NewGenerateTask() (Generate, error) {
	return &GenerateTask{}, nil
}
func (g *GenerateTask) Generate(ctx context.Context, generateParam GenerateParam) ([]TaskConfig, error) {
	tasks := []TaskConfig{}
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	num := 2 + r.Intn(5)
	for i := 0; i < num; i++ {
		tasks = append(tasks, TaskConfig{TaskID: fmt.Sprintf("%d", i)})
	}
	return tasks, nil
}

type GenerateParam struct {
	TaskType string
	TaskNum  int
}

type Generate interface {
	Generate(ctx context.Context, generateParam GenerateParam) ([]TaskConfig, error)
}

type RawData struct {
	Data []byte
}

//2. get data from Http API
type HttpTask struct {
}

func NewHttpTask() HttpAPI {
	return &HttpTask{}
}
func (h *HttpTask) GetData(ctx context.Context, url string) (*RawData, error) {
	taskID := ctx.Value(taskIDCtx).(string)
	log.Println("get data from", url, taskID)
	return &RawData{Data: []byte(taskID)}, nil
}

type HttpAPI interface {
	GetData(ctx context.Context, url string) (*RawData, error)
}

// 3. Kafka about
type KafkaClient struct {
}

func (c *KafkaClient) Produce(topic string, item KafkaItem) error {
	fmt.Println("produce", topic, item)
	return nil
}

type KafkaConfig struct {
	Endpoint string
}

func NewKafkaClient(cfg KafkaConfig) (KafkaAPI, error) {
	return &KafkaClient{}, nil
}

type KafkaItem struct {
	Data []byte
}
type ConsumerHandler func(item KafkaItem) error

type KafkaAPI interface {
	Produce(topic string, data KafkaItem) error
	// Consume(topic string, h ConsumerHandler)
}

func main() {
	generate, _ := NewGenerateTask()
	httpAPI := NewHttpTask()
	kafkaAPI, _ := NewKafkaClient(KafkaConfig{})
	taskManager := NewTaskManager(generate, httpAPI, kafkaAPI)
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()
	taskManager.Start(ctx)
	c := make(chan os.Signal, 1)
	signal.Notify(c, syscall.SIGINT, syscall.SIGTERM, syscall.SIGQUIT)
	select {
	case <-ctx.Done():
	case <-c:
		fmt.Println("end...")

	}
}
