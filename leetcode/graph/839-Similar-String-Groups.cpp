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
    int numSimilarGroups(vector<string>& str) {
        int n = str.size();
        vector<vector<int>> g(n,vector<int>());
        for(int i =0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(sim(str[i],str[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> visit(n,0);
        int c = 0;
        for(int i = 0; i< n; i++) {
            if(visit[i] == 0) {
                dfs(g,i,visit);
                c++;
            }
        }
        return c;
    }
    
    void dfs(vector<vector<int>> &g,int s,vector<int> &visit) {
        visit[s] = 1;
        for(auto e : g[s]) {
            if(!visit[e]){
                dfs(g,e,visit);
            }
        }
    }
    
    
    int sim(string &a,string &b) {
        int n = a.size();
        int diff= 0 ;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i])
                diff++;
        }
        return diff <=2;
    }
    int sim_help(string &a,string &b) {
        int n = a.size();
        vector<int> d;
        for(int i = 0; i < n && d.size() <= 2; i++) {
            if(a[i] != b[i]) {
                d.push_back(i);
            }
        }
        if(d.size() == 0)
            return 1;
        if(d.size() != 2)
            return 0;
        int i = d[0],j = d[1];
        return a[i] == b[j] && b[i] == a[j];
    }
};
int main() {
    Solution so;

    return 0;
}