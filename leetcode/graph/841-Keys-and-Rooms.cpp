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
    int c = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // return dfs_help(rooms);
        return whateverSearch2(rooms);
        // return whateverSearch(rooms);
    }
    bool dfs_help(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visit(n, 0);
        dfs(rooms, 0, visit);
        int x = 0;
        for (auto e : visit) {
            if (e == 1) {
                x++;
            }
        }
        return x == n;
    }
    //这种方式最快，在入队列前标记已访问
    int whateverSearch2(vector<vector<int>>& rooms) {
        stack<int> st;
        st.push(0);
        int n = rooms.size();
        vector<int> visit(n, 0);
        visit[0] = 1;
        while (!st.empty()) {
            auto s = st.top();
            st.pop();
            for (auto e : rooms[s]) {
                if (!visit[e]) {
                    visit[e] = 1;
                    st.push(e);
                }
            }
        }
        for (auto e : visit) {
            if (!e) {
                return 0;
            }
        }
        return 1;
    }

    int whateverSearch(vector<vector<int>>& rooms) {
        stack<int> st;
        st.push(0);
        int n = rooms.size();
        vector<int> visit(n, 0);
        while (!st.empty()) {
            auto s = st.top();
            st.pop();
            visit[s] = 1;
            for (auto e : rooms[s]) {
                if (!visit[e]) {
                    st.push(e);
                }
            }
        }
        int x = 0;
        for (auto e : visit) {
            if (e == 1) {
                x++;
            }
        }
        return x == n;
    }
    void dfs(vector<vector<int>>& g, int s, vector<int>& visited) {
        visited[s] = 1;
        // c++;
        for (auto e : g[s]) {
            if (!visited[e]) {
                dfs(g, e, visited);
            }
        }
    }
};
int main() {
    Solution so;
    vector<vector<int>> rooms;
    {
        rooms = {{1}, {2}, {3}, {}};
        auto r = so.canVisitAllRooms(rooms);
        cout << r << endl;
    }
    {
        rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
        auto r = so.canVisitAllRooms(rooms);
        cout << r << endl;
    }

    {
        rooms = {{1, 1}, {}};
        auto r = so.canVisitAllRooms(rooms);
        cout << r << endl;
    }
    return 0;
}