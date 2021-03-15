package main

import (
	// "container/ring"
	// "context"
	"fmt"
	// "sync"
	"math/rand"
	// "time"
)

// type Link struct {
// 	next *Node
// }
type Node struct {
	// key string
	val int
	// pre   *Node
	// pre   *Node
	forward []*Node
}

func NewNode(v int, level int) *Node {
	return &Node{
		val:     v,
		forward: make([]*Node, level+1),
	}
}

type List struct {
	head     *Node
	tail     *Node
	maxlevel int
	size     int
}

func (l *List) Empty() bool {
	return l.size == 0
}
func (l *List) Insert(v int) {
	n := NewNode(v, l.maxlevel)
	// x := l.search(v)
	x := l.head
	update := make([]*Node, l.maxlevel+1)
	for i := l.maxlevel; i >= 0; i-- {
		for x.forward[i] != nil && x.forward[i].val < v {
			x = x.forward[i]
		}
		update[i] = x
	}
	y := x.forward[0]
	if y != nil && y.val == v {
		return
	}
	height := l.RandomLevel()
	fmt.Println("height:", height)
	for i := 0; i < height; i++ {
		n.forward[i] = update[i].forward[i]
		update[i].forward[i] = n
	}
	l.size++

}

/// return pre_node for key word v
func (l *List) search(v int) *Node {
	x := l.head
	for i := l.maxlevel; i >= 0; i-- {
		for x.forward[i] != nil && x.forward[i].val < v {
			x = x.forward[i]
		}
	}
	//x.forward[i] is nil or x.forward[i] >= val
	return x
}
func (l *List) Search(v int) *Node {

	x := l.head

	for i := l.maxlevel; i >= 0; i-- {
		for x.forward[i] != nil && x.forward[i].val < v {
			x = x.forward[i]
		}
	}
	x = x.forward[0]
	if x != nil && x.val == v {
		return x
	}
	return nil
}
func (l *List) RandomLevel() int {
	height := 1
	p := float64(0.5)
	for rand.Float64() < p && height < l.maxlevel {
		height++
	}
	return height
}

func (l *List) PrintLevel(level int) {
	if level > l.maxlevel {
		return
	}
	c := 0
	fmt.Printf("level:%d -> [", level)
	x := l.head.forward[level]
	for x != l.tail {
		fmt.Printf("%d ", x.val)
		x = x.forward[level]
		c++
	}
	fmt.Printf("] %d\n", c)

}
func (l *List) print() {
	x := l.head.forward[0]
	for x != l.tail {
		fmt.Printf("%d ", x.val)
		x = x.forward[0]
	}
	fmt.Println()
}

const (
	dumpy  = (1 << 31) - 1
	ndumpy = -(1 << 31)
)

func NewList(level int) *List {
	l := &List{
		head:     NewNode(0, level+1),
		tail:     nil,
		maxlevel: level,
	}
	for i := level; i >= 0; i-- {
		l.head.forward[i] = l.tail
	}
	return l
}
func testRandomLevel() {
	l := NewList(5)
	N := 1000
	m := map[int]int{}
	for i := 0; i < N; i++ {
		x := l.RandomLevel()
		m[x]++
	}
	for k, v := range m {
		fmt.Println(k, float32(v)/float32(N))
	}
}
func main() {
	testRandomLevel()
	l := NewList(10)
	x := l.Search(ndumpy)
	fmt.Println(x)
	N := 1000
	for i := 0; i < N; i++ {
		l.Insert(i)
	}
	// l.print()
	l.PrintLevel(2)
	l.PrintLevel(5)
	l.PrintLevel(6)
	// fmt.Println(l.Search(48))
	// fmt.Println(l.Search(49))

}
