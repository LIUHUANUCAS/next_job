package main

import "sync"

// ChunkHandleID chunk id的管理，映射
type ChunkHandleID struct {
	ID         int64
	Mu         *sync.Mutex
	ChunkIDmap map[int64]*Chunk
}

func NewChunkHandleID() *ChunkHandleID {
	return &ChunkHandleID{
		ID:         0,
		Mu:         &sync.Mutex{},
		ChunkIDmap: make(map[int64]*Chunk),
	}
}
func (c *ChunkHandleID) GenerateID() int64 {
	c.Mu.Lock()
	defer c.Mu.Unlock()
	c.ID++
	return c.ID
}
