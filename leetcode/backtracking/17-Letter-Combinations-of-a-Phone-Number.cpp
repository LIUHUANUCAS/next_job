#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
public:
    const vector<string> pad = {
        "0", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        res ={};
        string path;
        dfs(digits,0,path);
        
        
        return res;
    }
    void dfs(string &s ,int start,string &path) {
        int n = s.size();
        if(start >= n) {
            res.push_back(path);
            return ;
        }
        int idx = s[start]-'0';
        for(auto e: pad[idx]) {
            path.push_back(e);
            dfs(s,start+1,path);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "23";
        auto r = so.letterCombinations(s);
        printvector<string>(r);
    }
    {
        s = "2";
        auto r = so.letterCombinations(s);
        printvector<string>(r);
    }
    {
        s = "654";
        auto r = so.letterCombinations(s);
        printvector<string>(r);
    }
    {
        s = "223";
        auto r = so.letterCombinations(s);
        printvector<string>(r);
    }
    return 0;
}