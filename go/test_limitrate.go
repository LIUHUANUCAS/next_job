package main

import (
	// "container/ring"
	// "context"
	"fmt"
	// "sync"
	"time"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

type TokenBucket struct {
	Rate       int64
	LastTime   int64
	TotalToken int64
	CurToken   int64
}

func NewTokenBucket(r int64) *TokenBucket {
	return &TokenBucket{
		Rate:       r * 1000,
		TotalToken: r * 1000,
		LastTime:   time.Now().UnixNano() / 1e6,
		CurToken:   0,
	}
}
func (t *TokenBucket) Allow() bool {
	now := time.Now().UnixNano() / 1e6
	addToken := t.Rate * (now - t.LastTime) / 1000
	t.LastTime = now
	allowToken := t.CurToken + addToken
	t.CurToken = min(allowToken, t.TotalToken)
	if t.CurToken < 1000 {
		return false
	}
	t.CurToken -= 1000
	return true
}
func main() {
	t := NewTokenBucket(50)
	// start := time.Now().Unix()
	c := 0
	start := time.Now()
	// app := []string{"A", "A", "A", "B", "C"}
	N := 300
	// for i := 0; i < 100; i++ {
	for i := 0; i < N; i++ {
		// for _, x := range app {
		if t.Allow() {
			fmt.Println("allow:", "x", i, time.Since(start))
			c++
		} else {
			fmt.Println("limit rate :", i, time.Since(start))
		}
		// }
		time.Sleep(5 * time.Millisecond)
	}
	fmt.Println(c, N, time.Since(start))
}
