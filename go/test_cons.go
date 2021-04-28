package main

import (
	// "container/ring"
	// "context"
	"fmt"
	// "sync"
	// "time"
)

// Data data
type Data struct {
	Data interface{}
	Next *Data
}

// NewCons new cons
func NewCons(d interface{}, data *Data) *Data {
	return &Data{d, data}
}

// Car first
func Car(d *Data) interface{} {
	return d.Data
}

// Cdr second
func Cdr(d *Data) *Data {
	return d.Next
}

// Traversal traversal data
func Traversal(d *Data, f func(x interface{})) {
	if d == nil {
		return
	}
	f(d.Data)
	Traversal(d.Next, f)
}
func main() {
	d := &Data{Data: 0}
	fmt.Println(d)

	for i := 1; i < 10; i++ {
		d = NewCons(i, d)
	}
	Traversal(d, func(x interface{}) {
		fmt.Println(x)
	})
}
