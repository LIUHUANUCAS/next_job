#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto& w : words) {
            m[w] += 1;
        }
        auto cmp = [&](const string a, const string& b) {
            return m[a] == m[b] ? a < b : m[a] > m[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> que(cmp);
        for (auto e : m) {
            que.push(e.first);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> res;
        while (!que.empty()) {
            auto x = que.top();
            que.pop();
            res.push_back(x);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution so;
    vector<string> words, r;
    int k;
    {
        words = {"i", "love", "leetcode", "i", "love", "coding"};
        k = 2;
        r = so.topKFrequent(words, k);
        printvector(r);
    }
    {
        words = {"the", "day", "is",    "sunny", "the",
                 "the", "the", "sunny", "is",    "is"};
        k = 4;
        r = so.topKFrequent(words, k);
        printvector(r);
    }
    return 0;
}