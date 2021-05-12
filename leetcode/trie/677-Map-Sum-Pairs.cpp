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
class MapSum {
    int val;
    int end;
    unordered_map<char, MapSum*> child;

   public:
    /** Initialize your data structure here. */
    MapSum() : val(0) {}

    void insert(string key, int val) {
        auto n = this;
        for (auto c : key) {
            if (n->child.find(c) == n->child.end()) {
                n->child[c] = new MapSum();
            }
            n = n->child[c];
        }
        n->val = val;
        n->end = 1;
    }

    int sum(string prefix) {
        int s = 0;
        auto n = this;
        for (auto c : prefix) {
            if (n->child.find(c) == n->child.end())
                return 0;
            n = n->child[c];
        }
        return dfs(n);
    }
    int dfs(MapSum* n) {
        if (n == nullptr)
            return 0;
        int s = 0;
        if (n->end) {
            s += n->val;
        }
        for (auto e : n->child) {
            s += dfs(e.second);
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
int main() {
    MapSum* obj;
    string key, prefix;
    int val, sum;
    {
        obj = new MapSum();
        vector<pair<string, int>> m = {{"apple", 3}, {"app", 2}};
        prefix = "app";
        for (auto e : m) {
            obj->insert(e.first, e.second);
        }
        sum = obj->sum(prefix);
        cout << sum << endl;
    }
    return 0;
}