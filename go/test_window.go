package main

import (
	// "container/ring"
	// "context"
	"fmt"
	// "sync"
	"time"
)

const (
	WindowTime = 10
)

type LimitWindow struct {
	LastTime int64
	Limit    int64
	Count    int64
}

func NewLimitWindow(limit int64) *LimitWindow {
	return &LimitWindow{
		LastTime: time.Now().UnixNano() / 1e6,
		Count:    0,
		Limit:    limit,
	}
}
func (l *LimitWindow) Allow() bool {
	now := time.Now().UnixNano() / 1e6
	l.Count++
	if now-l.LastTime > WindowTime {
		l.Count = 0
		l.LastTime = now
	}
	if l.Count < l.Limit {
		l.Count++
		return true
	}

	return false
}

func main() {
	start := time.Now()
	l := NewLimitWindow(10)
	N := 10000
	c := 0
	for i := 0; i < N; i++ {
		allow := "limit:"
		if l.Allow() {
			allow = "allow"
			c++
			fmt.Println(i)
		}
		fmt.Println(allow, i)
	}
	fmt.Println("end", time.Since(start), c, N)
}
