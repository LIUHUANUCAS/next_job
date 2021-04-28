package main

import (
	// "container/ring"
	// "context"
	"fmt"
	"os"
	"strings"
)

type Node struct {
	dirname string
	child   map[string]*Node
	files   map[string]int
}

func NewNode(dir string) *Node {
	return &Node{
		dirname: dir,
		child:   make(map[string]*Node),
		files:   make(map[string]int),
	}
}
func (n *Node) ExitDir(dir string) bool {
	_, ok := n.child[dir]
	return ok
}
func (n *Node) NextNode(dir string) *Node {
	if p, ok := n.child[dir]; ok {
		return p
	}
	return nil
}
func (n *Node) find(file string) *Node {
	files := strings.Split(file, "/")
	fmt.Println(files)
	p := n
	for _, dir := range files[:len(files)-1] {
		if p.ExitDir(dir) {
			p = p.NextNode(dir)
		} else {
			return nil
		}
	}
	fname := files[len(files)-1]
	if _, ok := p.files[fname]; ok {
		return p
	}
	return nil
}
func (n *Node) Add(file string) {
	files := strings.Split(file, "/")
	fmt.Println(files[:len(files)-1])
	p := n
	c := 1
	dirs := []string{}
	if len(files) >= 2 {
		dirs = files[1 : len(files)-1]
	}
	for _, dir := range dirs {
		fmt.Println("dir:", dir)
	}
	for _, dir := range dirs {
		fmt.Println("cur:", p, dir)
		if p.ExitDir(dir) {
			p = p.NextNode(dir)
		} else {
			p.child[dir] = NewNode(dir)
			p = p.child[dir]
		}
		c++
	}
	filename := files[len(files)-1]
	fmt.Println("basefilename:", filename)
	p.files[filename] = c
}
func PrintTree(n *Node, c int) {
	if n == nil {
		return
	}
	printblank(c - 1)
	x := "|-- %s\n"
	fmt.Printf(x, n.dirname)
	for k := range n.files {
		printblank(c)
		fmt.Printf(x, k)
	}
	for _, v := range n.child {
		// fmt.Println()
		// fmt.Println(v)
		PrintTree(v, c+1)
	}
}
func printblank(c int) {
	// if c <= 0 {
	// 	return
	// }
	x := "|"
	if c == 0 {
		x = ""
	}
	fmt.Printf(x)
	y := "    "
	for i := 0; i < c; i++ {
		fmt.Printf(y)
	}
	// fmt.Printf(" ")
}
func (n *Node) Print() string {
	// p := n

	return ""
}
func main() {
	n := NewNode("/")
	n.Add("/usr/local/service/a.log")
	n.Add("/usr/local/a.log")
	n.Add("/share/local/a.log")
	array := []string{
		"/usr/local/c.txt",
		"/root/trpc/tool_data/crc32.sh",
		"/root/trpc/tool_data/create_plugin.sh",
		"/root/trpc/tool_data/docs",
		"/root/trpc/tool_data/eating",
		"/root/trpc/tool_data/go",
		"/root/trpc/tool_data/md",
		"/root/trpc/tool_data/README.md",
		"/root/trpc/tool_data/sh",
	}
	fmt.Println(array)
	fmt.Println(os.Args[1:])
	// for _, name := range array {
	// 	n.Add(name)
	// }

	for _, name := range os.Args[1:] {
		n.Add(name)
	}
	fmt.Println(n)
	fmt.Println("-------------------")
	n.Print()
	PrintTree(n, 1)
}
