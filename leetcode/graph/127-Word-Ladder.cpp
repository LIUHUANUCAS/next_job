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
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& list) {
        int n = list.size(), end = -1, s = 0;
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            if (diff(beginWord, list[i])) {
                g[s].push_back(i + 1);
            }
            if (endWord == list[i]) {
                end = i + 1;
            }
        }
        // printf("%d->", s);
        // printvector(g[0]);
        if (end < 0 || g[s].size() == 0)
            return 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (diff(list[i], list[j])) {
                    g[i + 1].push_back(j + 1);
                    g[j + 1].push_back(i + 1);
                }
            }
            // printf("%d->", i + 1);
            // printvector(g[i + 1]);
        }
        // printvector(g[0]);
        auto path = bfs(g, s, end);
        return path.size();
    }

    // getpath from end to s
    vector<int> getpath(vector<int>& pathto, int s, int end) {
        int x = end;
        vector<int> path = {s};
        while (x != s) {
            path.push_back(x);
            x = pathto[x];
            // printf("%d<-", x);
        }
        // cout << endl;
        return path;
    }
    // return pathto end
    vector<int> bfs(vector<vector<int>>& g, const int s, const int end) {
        // printf("path:%d %d\n", s, end);
        int size = g.size();
        vector<int> visit(size, 0), pathto(size, 0), dist(size, INT_MAX);
        queue<int> que;
        dist[s] = 0;
        que.push(s);
        while (!que.empty()) {
            auto x = que.front();
            que.pop();
            for (auto adj : g[x]) {
                if (dist[adj] > dist[x] + 1) {
                    dist[adj] = dist[x] + 1;
                    que.push(adj);
                    pathto[adj] = x;
                }
            }
        }
        if (dist[end] != INT_MAX) {
            return getpath(pathto, s, end);
        }
        return {};
    }
    int diff(string& s, string& t) {
        if (t.size() != s.size())
            return 0;
        int n = s.size(), c = 0;
        for (int i = 0; i < n && c <= 1; i++) {
            if (s[i] != t[i])
                c++;
        }
        return c == 1;
    }
};
int main() {
    Solution so;
    string beginWord, endWord;
    vector<string> wordList;
    int r;
    {
        beginWord = "hit", endWord = "cog",
        wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        r = so.ladderLength(beginWord, endWord, wordList);
        cout << r << endl;
    }
    {
        beginWord = "hot", endWord = "dog", wordList = {"hot", "dog", "dot"};
        r = so.ladderLength(beginWord, endWord, wordList);
        cout << r << endl;
    }
    {
        beginWord = "hit", endWord = "cog",
        wordList = {"hot", "dot", "dog", "lot", "log"};
        r = so.ladderLength(beginWord, endWord, wordList);
        cout << r << endl;
    }

    {
        beginWord = "hit", endWord = "cog",
        wordList = {"hot", "dot", "tog", "cog"};
        r = so.ladderLength(beginWord, endWord, wordList);
        cout << r << endl;
    }
    return 0;
}