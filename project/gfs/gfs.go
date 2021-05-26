package main

import (
	"fmt"
)

const (
	ChunkSize = 64 * 1024 * 1024 // 64MB
)

type Master struct {
}

type ChunkServer struct {
}

// MetaData in master
type MetaData struct {
	trieNode      *TrieNode
	chunkHandleID *ChunkHandleID
	filemap       map[string]*File
}

func (m *MetaData) Add(filename string, content []byte) {
	f, ok := m.filemap[filename]

}
func NewMetaData() *MetaData {
	return &MetaData{
		trieNode:      NewTrieNode(),
		chunkHandleID: NewChunkHandleID(),
		filemap:       make(map[string]*File),
	}
}

type File struct {
	Filename string   // 文件名
	Chunks   []*Chunk // chunk 分块
}

func (f *File) Append(c *Chunk) { // 追加
	f.Chunks = append(f.Chunks, c)
}
func (f *File) SetChunk(idx int, c *Chunk) { // 设置
	f.Chunks[idx] = c
}

// Chunk data
type Chunk struct {
	Filename     string // 文件名
	Size         int64  // 文件大小
	ChunkHandle  int64  // chunk-handle
	ChunkIndex   int64  // chunk 序号
	CheckSum     uint32 // 校验和
	Content      []byte // chunk内容，仅在chunk-server上有
	Host         string // 地址，ip:port形式
	Ref          int32  // Chunk 引用
	ChunkVersion int32  // Chunk 版本，租约使用
}

type ReadMetaReq struct {
	Filename   string // 文件名
	ChunkIndex int64  // ChunkIndex
}
type ChunkLocation struct {
	IP   string
	Port int32
}
type ReadMetaResp struct {
	Filename      string
	ChunkIndex    int64
	ChunkHandle   int64           // ChunkHandle
	ChunkLocation []ChunkLocation // Chunk地址，可能有多个，失败之后重试其他的地址
}

type ReadReq struct {
	ByteStart   int64 // 起始位置
	ByteEnd     int64 // 终止位置
	ChunkHandle int64 // ChunkHandle
}

type MasterChunk struct {
	Chunk
}
type ServerChunk struct {
	Chunk
}

func main() {
	fmt.Println("GFS")
}
