package main

import (
	// "container/ring"
	// "context"
	"encoding/json"
	"fmt"
	// "sync"
	"time"
)

var (
	log = fmt.Println
)

type ReqMsg struct {
	Method string
	Class  string
}
type RespMsg struct {
	reply []byte
}
type Server struct {
	SvrMap map[string]Service
	ch1    chan []byte
	ch2    chan []byte
}

func (s *Server) Add(name string, svc Service) {
	if _, ok := s.SvrMap[name]; ok {
		return
	}
	s.SvrMap[name] = svc
}

func (s *Server) Del(name string) {
	if _, ok := s.SvrMap[name]; ok {
		delete(s.SvrMap, name)
		return
	}
}

type Service struct {
}

func (s *Service) Add(a, b int) int {
	return a + b
}

type Client struct {
	req   ReqMsg
	cc    Codec
	trans Transport
}
type Transport struct {
	reqCh  chan []byte
	respCh chan []byte
}

func (t *Transport) Send(d []byte) error {

	select {
	case t.reqCh <- d:
		log("send success")
	case <-time.After(time.Millisecond * 10):
		log("send error ")
		return fmt.Errorf("timeout send")
	}
	return nil
}

type Codec struct {
}

func (c *Codec) Encode(d interface{}) ([]byte, error) {
	return json.Marshal(d)
}
func (c *Codec) Decode(b []byte, d interface{}) error {
	return json.Unmarshal(b, &d)
}
func (c *Client) Call() error {
	b, err := c.cc.Encode(c.req)
	if err != nil {
		return err
	}
	if err := c.trans.Send(b); err != nil {
		log(err)
		return err
	}
	return nil

}
func main() {
	netCh1 := make(chan []byte)
	netCh2 := make(chan []byte)

	svr := &Server{
		ch1:    netCh1,
		ch2:    netCh2,
		SvrMap: make(map[string]Service),
	}
	svr.Add("Service.Add", Service{})
	c := &Client{
		cc:    Codec{},
		trans: Transport{netCh1, netCh2},
	}
	msg := ReqMsg{
		Method: "Add",
		Class:  "Service",
	}
	c.req = msg
	c.Call()
	fmt.Println()
}
