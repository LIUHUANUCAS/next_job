#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
struct Data {
    int index;
    int val;
    int snap_id;
    Data(int i = 0, int v = 0, int id = 0) : index(i), val(v), snap_id(id) {}
};
class SnapshotArray {
    int snap_id;
    vector<vector<Data>> array;

   public:
    SnapshotArray(int length) {
        array = vector<vector<Data>>(length);
        snap_id = 0;
        for (int i = 0; i < length; i++) {
            array[i].push_back(Data(i, 0, snap_id));
        }
    }

    void set(int index, int val) {
        // same snap_id
        if (array[index].back().snap_id == snap_id) {
            array[index].back().val = val;
            return;
        }
        // old snap_id
        array[index].push_back(Data(index, val, snap_id));
    }

    int snap() { return snap_id++; }

    int get(int index, int id) {
        auto cmp = [](const Data& a, const Data& b) {
            return a.snap_id < b.snap_id;
        };
        // binary search for [snap_id, now_snap_id ]
        auto it = upper_bound(array[index].begin(), array[index].end(),
                              Data(0, 0, id), cmp);

        return it == array[index].begin() ? 0 : (--it)->val;
        // return it->val;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main() {
    int val, snap_id = -1;
    // set the length to be 3
    SnapshotArray* snapshotArr = new SnapshotArray(3);
    snapshotArr->set(0, 5);         // Set array[0] = 5
    snap_id = snapshotArr->snap();  // Take a snapshot, return snap_id = 0
    cout << snap_id << endl;
    snapshotArr->set(0, 6);
    // Get the value of array[0] with snap_id = 0, return 5
    val = snapshotArr->get(0, 0);
    cout << val << endl;
    snap_id = snapshotArr->snap();
    cout << snap_id << endl;
    snapshotArr->set(0, 18);
    val = snapshotArr->get(0, 1);
    cout << val << endl;

    return 0;
}