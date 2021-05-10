package main

import (
	// "encoding/json"
	"context"
	"fmt"
	"sync"
	"time"
)

/**
1.implement a task queue
2.concurrency control
3.timeout
4.cancel task
5.how to test
*/
/**
一些其他问题：
1、如何测试启动的goroutine数量
2、如何测试完成的任务量
*/

type Func func()

type Queue struct {
	concurrency int
	tasklist    chan Func
	timeout     time.Duration
	cancel      context.CancelFunc
	wg          *sync.WaitGroup
}

func Send(url string) {
	fmt.Println("send:", url)
}
func NewQueue(concurrency int, timeout time.Duration) *Queue {
	ctx, cancel := context.WithCancel(context.Background())
	q := &Queue{
		concurrency: concurrency,
		timeout:     timeout,
		tasklist:    make(chan Func),
		cancel:      cancel,
		wg:          &sync.WaitGroup{},
	}
	q.Task(ctx)
	return q
}
func (q *Queue) Task(ctx context.Context) {
	fmt.Println("begin task")
	for i := 0; i < q.concurrency; i++ {
		q.wg.Add(1)
		go func() {
			defer q.wg.Done()

			for {
				select {
				case <-ctx.Done():
					fmt.Println("done ... all task ")
					return
				case f := <-q.tasklist:
					<-FuncWithTimeout(f, q.timeout)
					// f()
					fmt.Println("end execute task")
				}
			}
		}()
	}
}

func FuncWithTimeout(f Func, timeout time.Duration) chan struct{} {
	ch := make(chan struct{})
	go func() {
		f()
		ch <- struct{}{}
	}()
	res := make(chan struct{}, 1)
	select {
	case <-ch:
		fmt.Println("task done ")
	case <-time.After(timeout):
		fmt.Println("timeout")

	}
	res <- struct{}{}
	return res
}

// func comsumer() {

// 	for f := range q.tasklist {
// 		// ctx, cancal := context.ContextWithTimeout(q.timeout)
// 		// f(ctx)
// 		end := make(chan struct{})
// 		go func() {
// 			f()
// 			end <- struct{}{}
// 		}()
// 		select {
// 		case <-end:
// 			fmt.Println("end line ", f)
// 		case <-time.After(q.timeout):
// 		}
// 	}
// }
func (q *Queue) Stop() {
	// close(q.tasklist)
	q.Cancel()
}
func (q *Queue) Cancel() {
	fmt.Println("cancel queue ")
	q.cancel()
	q.wg.Wait() // wait for done
	close(q.tasklist)
	fmt.Println("end for queue")
}
func (q *Queue) EnQueue(url string) {
	q.tasklist <- func() {
		Send(url)
	}
}
func main() {
	// res := FuncWithTimeout(func() { fmt.Println("end") }, time.Second*1)
	// <-res
	TestCase()
}
func TestCase() {
	c := 10
	url := "http://www.qq.com"
	timeout := time.Second * 1
	q := NewQueue(c, timeout)
	N := 100
	for i := 0; i < N; i++ {
		q.EnQueue(url)
	}
	q.Stop()
	time.Sleep(time.Second * 1)

}
