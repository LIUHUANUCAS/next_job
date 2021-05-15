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
class TimeMap {
    unordered_map<string, map<int, string>> m;

   public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (m.find(key) == m.end()) {
            m[key] = map<int, string>();
        }
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main() {
    string key("hello"), value("world");
    int timestamp = 10;
    TimeMap* obj = new TimeMap();
    obj->set(key, value, timestamp);
    string r = obj->get(key, timestamp);
    cout << r << endl;
    return 0;
}