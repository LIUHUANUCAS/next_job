package main

import (
	"fmt"
)

type Data struct {
	index  int
	val    interface{}
	snapID int64
}

func NewData(i int, snapID int64, v interface{}) Data {
	return Data{
		index:  i,
		snapID: snapID,
		val:    v,
	}
}

// SnapShot for file
type SnapShot struct {
	snapID    int64
	dataArray [][]Data
}

func NewSnapShot(length int32) SnapShot {
	s := SnapShot{
		snapID:    0,
		dataArray: make([][]Data, length),
	}
	for i := 0; i < int(length); i++ {
		s.dataArray[i] = append(s.dataArray[i], NewData(int64(i), 0, nil))
	}
	return s
}
func (s *SnapShot) Set(idx int, v interface{}) {
	if s.dataArray[idx][len(s.dataArray[idx])-1].snapID == s.snapID {
		s.dataArray[idx][len(s.dataArray[idx])-1].val = v
		return
	}
	s.dataArray[idx] = append(s.dataArray[idx], NewData(idx, s.snapID, v))
}
func (s *SnapShot) Snap() int64 {
	v := s.snapID
	s.snapID++
	return v
}
func (s *SnapShot) Get(idx int, snapid int64) *Data {
	index := find(s.dataArray[idx], snapid)
	if index == 0 {
		return nil
	}
	index--
	return &s.dataArray[idx][index]
}
func find(d []Data, snapid int64) int {
	return 0
}

// struct Data {
//     int index;
//     int val;
//     int snap_id;
//     Data(int i = 0, int v = 0, int id = 0) : index(i), val(v), snap_id(id) {}
// };
// class SnapshotArray {
//     int snap_id;
//     vector<vector<Data>> array;

//    public:
//     SnapshotArray(int length) {
//         array = vector<vector<Data>>(length);
//         snap_id = 0;
//         for (int i = 0; i < length; i++) {
//             array[i].push_back(Data(i, 0, snap_id));
//         }
//     }

//     void set(int index, int val) {
//         // same snap_id
//         if (array[index].back().snap_id == snap_id) {
//             array[index].back().val = val;
//             return;
//         }
//         // old snap_id
//         array[index].push_back(Data(index, val, snap_id));
//     }

//     int snap() { return snap_id++; }

//     int get(int index, int id) {
//         auto cmp = [](const Data& a, const Data& b) {
//             return a.snap_id < b.snap_id;
//         };
//         // binary search for [snap_id, now_snap_id ]
//         auto it = upper_bound(array[index].begin(), array[index].end(),
//                               Data(0, 0, id), cmp);

//         return it == array[index].begin() ? 0 : (--it)->val;
//         // return it->val;
//     }
// };
