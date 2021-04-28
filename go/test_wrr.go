package main

import (
	"fmt"
)

// Node weight round robin
type Node struct {
	Weight        int64
	CurrentWeight int64
	Name          string
	Idx           int64
}

func (n *Node) String() string {
	return n.Name
}

// WeightRoundRobin weight
type WeightRoundRobin struct {
	list []*Node
}

// Select select node
func (w *WeightRoundRobin) Select() *Node {
	total := int64(0)
	var best *Node
	for _, node := range w.list {

		total += node.Weight
		node.CurrentWeight += node.Weight
		if best == nil || best.CurrentWeight < node.Weight {
			best = node
		}
	}
	best.CurrentWeight -= total
	return best
}

func main() {
	weight := []int64{1, 3, 2, 5}
	w := &WeightRoundRobin{}
	N := int64(0)
	for _, v := range weight {
		N += v
	}
	for i, wei := range weight {
		n := &Node{wei, 0, fmt.Sprintf("host_%d", i+1), int64(i) + 1}
		w.list = append(w.list, n)
		// N += wei
		fmt.Printf("%s:%d %f ", n, wei, float64(wei)/float64(N))
	}
	fmt.Println()
	N = int64(10000 * 100)
	m := map[string]int{}
	for i := int64(0); i < N; i++ {
		n := w.Select()
		// fmt.Printf("round_%d,select:%+v\n", i+1, n)
		m[n.String()]++
	}
	for k, v := range m {
		fmt.Printf("%s %f \n", k, float64(v)/float64(N))
	}
}
