#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    const vector<char> list = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> set(bank.begin(), bank.end());
        queue<string> que;
        que.push(start);
        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto w = que.front();
                que.pop();
                if (w == end) {
                    return level;
                }
                set.erase(w);                         // remove self
                for (int j = 0; j < w.size(); j++) {  // get adj-list
                    char ch = w[j];

                    for (auto c : list) {
                        w[j] = c;                        // only one char diff
                        if (set.find(w) != set.end()) {  // not self
                            que.push(w);                 // adj list
                        }
                    }
                    w[j] = ch;  // reset word[i]
                }
            }
            level++;
        }
        return -1;
    }
};
int main() {
    Solution so;
    string start, end;
    vector<string> bank;
    {
        start = "AACCGGTT", end = "AACCGGTA";
        bank = {"AACCGGTA"};
        auto r = so.minMutation(start, end, bank);
        cout << r << endl;
    }
    {
        start = "AACCGGTT", end = "AAACGGTA";
        bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        auto r = so.minMutation(start, end, bank);
        cout << r << endl;
    }
    {
        start = "AAAAACCC", end = "AACCCCCC",
        bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        auto r = so.minMutation(start, end, bank);
        cout << r << endl;
    }

    {
        start = "AACCGGTT", end = "AACCGCTA",
        bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        auto r = so.minMutation(start, end, bank);
        cout << r << endl;
    }

    return -1;
}