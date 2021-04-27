package main

/**
	hotstar
	一面：项目经历、链表表示的数，相加
	二面：项目经历、实现一个任务队列，
	三面：文本内容，里面有单词出错，比如出现a[uthe]r 写成了 a[theu]r 出错，
		目标：找到出错的单词，并纠正，如果无法纠正，直接输出
		发布服务的问题：操作服务发布过程有延迟，需要如何处理？
		最近在关注的一些技术，ddia

*/
type Func func()

type Queue struct {
	Con     int
	timeout time.Second
	ch chan Func 
}
func NewQueue(concurrency int ,timeout time.Second) *Queue{
	q := &Queue{
		Con : concurrency,
		timeout time.Second 
		ch :make(chan Func)
	}
	go q.Task()
	return q
}
func (q *Queue)Task() {
	for i:= 0; i < q.Con; i++ {
		go func(){
			for f := range q.ch {
				f()
			}
		}()
	}
}
func (q *Queue)Add (url string ) {
	f := func(){
		Send(url)
	}
	q.ch <- f
}

func main() {

}
