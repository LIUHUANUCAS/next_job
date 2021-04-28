package main

import (
	// "container/ring"
	"context"
	"fmt"
	"sync"
	"time"
)

// JobFunc job func
type JobFunc func()

// Job data
type Job struct {
	data interface{}
	f    JobFunc
}

// Pool pool
type Pool struct {
	ctx        context.Context
	wg         *sync.WaitGroup
	workers    int
	jobChan    chan *Job
	cancelFunc context.CancelFunc
}

// NewPool new pool
func NewPool(jobLen, workers int) *Pool {
	pool := &Pool{
		jobChan: make(chan *Job, jobLen),
		wg:      &sync.WaitGroup{},
		workers: workers,
	}

	return pool
}

//Start pool
func (p *Pool) Start() {
	ctx, cancel := context.WithCancel(context.Background())
	p.cancelFunc = cancel
	p.ctx = ctx
	p.start()
}

// Stop stop pool
func (p *Pool) Stop() {
	p.cancelFunc()
	p.wg.Wait()
}
func (p *Pool) start() {
	p.wg.Add(p.workers)
	// job := &Job{}
	for i := 0; i < p.workers; i++ {
		go func(idx int) {
			defer p.wg.Done()
			for {
				select {
				case <-p.ctx.Done():
					fmt.Println("done for worker:", idx)
					return
				case job := <-p.jobChan:
					job.f()
				}
			}
		}(i)
	}
}

// Put put task
func (p *Pool) Put(d *Job) error {
	select {
	case p.jobChan <- d:
		fmt.Println("finish put:", d)
	case <-time.After(time.Millisecond * 20):
		return fmt.Errorf("timeout put err")
	}
	return nil
}

func dofunc() {
	fmt.Println("task data:")
}

type JobData struct {
	d interface{}
}

func (j *JobData) DoTask() {
	fmt.Println("task:", j.d)
}
func getData(p *Pool) {
	i := 0
	for {
		i++
		j := JobData{d: i}
		p.Put(&Job{i, j.DoTask})

	}
}
func FinishData() {

}

type State struct {
	s int
}
type Conf struct {
	c int
}

func Do(s *State, conf *Conf) int {
	// fmt.Println("add:", s.s)
	s.s++
	return s.s
}
func main() {
	p := NewPool(10, 10)
	p.Start()
	for i := 0; i < 100; i++ {
		j := JobData{d: i}
		p.Put(&Job{i, j.DoTask})
	}
	p.Stop()
	s := &State{0}
	conf := &Conf{}
	for i := 0; i < 100; i++ {
		Do(s, conf)
	}
	ch, ch2 := make(chan int), make(chan int)
	wg := sync.WaitGroup{}
	for {
		wg.Add(1)
		go func() {
			wg.Done()
			f()
		}()
		fmt.Println("begin")
		select {
		case <-ch:
			break
		case <-ch2:
			fmt.Println("break2")
			break
		}
		fmt.Println("end")
	}
}
func f() {
	i := 0
	for {
		i++
		i %= 100
	}
}
