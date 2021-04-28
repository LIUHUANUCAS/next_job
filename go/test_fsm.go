package main

import (
	"math/rand"
	// "container/ring"
	// "context"
	"fmt"
	// "sync"
	// "time"
)

type Func func(s State) int

type State struct {
	CurState  int
	NextState int
	PreState  int
	f         Func
}
type Driver struct {
	m         map[int]State
	initState State
}

func NewDriver() *Driver {
	return &Driver{m: make(map[int]State)}
}
func (d *Driver) Register(l []State) {
	for _, k := range l {
		d.m[k.CurState] = k
	}
}
func (d *Driver) SetInit(s State) {
	d.initState = s
}

const End = 9999

func (d Driver) Run() {
	cur := d.initState
	for {
		nextState := d.m[cur.CurState].f(cur)
		if nextState == End {
			break
		}
		cur = d.m[nextState]
	}
}

func main() {
	list := []State{
		State{CurState: -1, f: func(s State) int {
			fmt.Println("first status", s.CurState)
			return 0
		}},
		State{CurState: 0, f: func(s State) int {
			fmt.Println("second  status:", s.CurState)
			return 1
		}},
		State{CurState: 1, f: func(s State) int {
			fmt.Printf("1 status:%d\n", s.CurState)
			return 2
		}},
		State{CurState: 2, f: func(s State) int {
			x := rand.Intn(s.CurState + 2)
			fmt.Printf("2 status:%d... %d %d \n", s.CurState, x, s.CurState+2)
			return x
		}},
		State{CurState: 3, f: func(s State) int {
			fmt.Println("end...")
			return 9999
		}},
	}
	d := NewDriver()
	d.Register(list)
	d.SetInit(list[0])
	d.Run()
}
