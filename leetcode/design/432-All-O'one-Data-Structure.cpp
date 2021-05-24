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
class AllOne {
    // key->set_iterator
    unordered_map<string, set<pair<int, string>>::iterator> m;
    set<pair<int, string>> s;  // value set

   public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key
     * by 1. */
    void inc(string key) {
        // printf("key:%s %ld %ld\n", key.c_str(), m.size(), s.size());
        if (m.find(key) == m.end()) {
            m[key] = s.insert({1, key}).first;
            return;
        }
        auto it = m[key];
        int val = it->first;
        s.erase(it);
        m[key] = s.insert({val + 1, key}).first;
        // printset();
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the
     * data structure. */
    void dec(string key) {
        if (m.find(key) == m.end()) {
            return;
        }
        auto it = m[key];
        int val = it->first;
        s.erase(it);
        if (val == 1) {
            m.erase(key);
            return;
        }
        m[key] = s.insert({val - 1, key}).first;
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (s.empty())
            return "";
        return s.rbegin()->second;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (s.empty())
            return "";
        return s.begin()->second;
    }
};
void printset() {
    cout << "---------------" << endl;
    for (auto e : s) {
        cout << e.first << ":" << e.second << " ";
    }
    cout << "\n";  //----------------" << endl;
}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 ["AllOne","inc","inc","inc","inc","getMaxKey","inc","inc","inc","dec","inc","inc","inc","getMaxKey"]
[[],["hello"],["goodbye"],["hello"],["hello"],[],["leet"],["code"],["leet"],["hello"],["leet"],["code"],["code"],[]]
 */
int main() {
    AllOne* obj = new AllOne();
    string key, max_key, min_key;
    vector<string> keys = {"hello", "goodbye", "hello", "hello"};
    for (auto k : keys) {
        obj->inc(k);
    }
    max_key = obj->getMaxKey();
    cout << max_key << endl;
    keys = {"leet", "code", "leet"};
    for (auto k : keys) {
        obj->inc(k);
    }
    obj->dec("hello");
    keys = {"leet", "code", "code"};
    min_key = obj->getMinKey();
    return 0;
}