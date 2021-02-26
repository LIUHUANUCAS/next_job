#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (auto& s : strs) {
            string t(s);
            sort(t.begin(), t.end());
            umap[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto e : umap) {
            res.push_back(e.second);
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<string> A;
    A = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r = so.groupAnagrams(A);
    for (auto& d : r)
        printvector(d);
    return 0;
}
