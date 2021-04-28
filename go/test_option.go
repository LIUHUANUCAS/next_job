package main

import (
	// "container/ring"
	// "context"
	"fmt"
)

type Client struct {
	Name string
	Age  int32
}

type Option func(*Client)

func WithName(name string) Option {
	return func(o *Client) {
		o.Name = name
	}
}
func WithAge(age int32) Option {
	return func(o *Client) {
		o.Age = age
	}
}
func NewClient(opts ...Option) *Client {
	c := &Client{}
	for _, opt := range opts {
		opt(c)
	}
	return c
}
func main() {
	opt := []Option{WithAge(13), WithName("hello")}

	// fmt.Println(o)
	age := WithAge(11)
	c := NewClient(age)
	fmt.Println(c)
	for _, o := range opt {
		o(c)
	}
	fmt.Println(c)

}
