package main

type TrieNode struct {
	end   bool
	Value interface{}
	child map[string]*TrieNode
}

func NewTrieNode() *TrieNode {
	return &TrieNode{
		child: make(map[string]*TrieNode),
	}
}

func (t *TrieNode) Add(path []string, v interface{}) {
	n := t
	for _, p := range path {
		n, ok := n.child[p]
		if !ok {
			n.child[p] = NewTrieNode()
		}
		n = n.child[p]
	}
	n.end = true
	n.Value = v
}
func (t *TrieNode) End() bool {
	return t.end
}
func (t *TrieNode) Search(path []string) *TrieNode {
	n := t
	for _, p := range path {
		if v, ok := n.child[p]; !ok {
			return nil
		}
		n = n.child[p]
	}
	if n.End() {
		return n
	}
	return nil
}
