#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;  // pair is [key,value];

   public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        auto val = m[key]->second;
        move_head(key, val);
        // auto it = m[key];
        // int val = it->second;
        // l.erase(it);
        // l.push_front({key, val});
        // m[key] = l.begin();
        return val;
    }
    void move_head(int key, int value) {
        auto it = m[key];
        l.erase(it);
        l.push_front({key, value});
        m[key] = l.begin();
    }
    void insert(int key, int value) {
        l.push_front({key, value});
        m[key] = l.begin();
    }
    void put(int key, int value) {
        if (m.find(key) != m.end()) {  // update
            move_head(key, value);
            // auto it = m[key];
            // l.erase(it);
            // l.push_front({key, value});
            // m[key] = l.begin();
            // printlist();
            return;
        }
        insert(key, value);
        // l.push_front({key, value});
        // m[key] = l.begin();
        if (m.size() > capacity) {
            evict();
        }
    }
    void evict() {
        auto last = l.back();
        int key = last.first, val = last.second;
        auto it = m[key];
        l.erase(it);
        m.erase(key);
    }
    void printmap() {
        for (auto e : m) {
            printf("map:[%d %d] ", e.first, e.second->second);
        }
        cout << endl;
    }
    void printlist() {
        for (auto it = l.begin(); it != l.end(); ++it) {
            printf("[%d %d]->", it->first, it->second);
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    // Solution so;
    int capacity = 2, key, value, r;
    LRUCache* obj = new LRUCache(capacity);
    // int r = obj->get(key);
    // put [2,1]
    key = 2, value = 1;
    obj->put(key, value);
    // put [1,1]
    key = 1, value = 1;
    obj->put(key, value);
    // get 2
    key = 2;
    r = obj->get(key);
    printf("key:%d %d\n", key, r);
    key = 4, value = 1;
    obj->put(key, value);
    key = 2;
    r = obj->get(key);
    printf("key:%d %d\n", key, r);

    // [ "LRUCache", "put", "put", "get", "put", "get",
    //   "get" ][[2], [ 2, 1 ], [ 1, 1 ], [2], [ 4, 1 ], [1], [2]]
    return 0;
}