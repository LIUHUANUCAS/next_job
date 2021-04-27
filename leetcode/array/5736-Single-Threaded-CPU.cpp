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
    unordered_map<int, vector<int>> exe;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // vector<int> start(n, 0);
        for (int i = 0; i < n; i++) {
            // start[i] = tasks[i][0];
            exe[i] = tasks[i];
        }
        // sort(start.begin(), start.end());
        vector<int> order(n, 0);
        int starttime = get_early_time();
        for (int i = 0; i < n; i++) {
            auto t = get_available_task(tasks, starttime);
            int idx = get_task(tasks, t);
            order[i] = idx;
            exe.erase(idx);
            starttime = tasks[idx][0] + tasks[idx][1];
            int y = get_early_time();
            if (starttime < y) {
                starttime = y;
            }
        }
        return order;
    }
    int get_task(vector<vector<int>>& tasks, vector<int>& available) {
        int i = -1;
        for (auto idx : available) {
            if (i < 0) {
                i = idx;
            } else {
                if (tasks[i][1] > tasks[idx][1]) {
                    i = idx;
                } else if (tasks[i][1] == tasks[idx][1]) {
                    i = min(idx, i);
                }
            }
        }
        return i;
    }
    int get_early_time() {
        int m = INT_MAX;
        for (auto e : exe) {
            m = min(e.second[0], m);
        }
        return m;
    }
    vector<int> get_available_task(vector<vector<int>>& task, int starttime) {
        vector<int> r;
        for (auto e : exe) {
            if (e.second[0] <= starttime) {
                r.push_back(e.first);
            }
        }
        return r;
    }

    // int select_ealry(vector<vector<int>>& tasks, int idx) {
    //     int n = tasks.size();
    //     for (int i = 0; i < n; i++) {
    //         if (exe.find(i) == exe.end()) {
    //         }
    //     }
    // }

    // int select_shortest(vector<vector<int>>& tasks, int starttime) {
    //     int n = tasks.size();
    //     int idx = -1;
    //     for (int i = 0; i < n; i++) {
    //         if (exe.find(i) == exe.end() && tasks[i][0] <= starttime) {
    //             // idx = min(idx, i);
    //             if (idx == -1) {
    //                 idx = i;
    //             } else {
    //                 if (tasks[i][1] <= tasks[idx][1]) {
    //                 }
    //             }
    //         }
    //     }
    //     return idx;
    // }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
        auto r = so.getOrder(A);
        printvector(r);
    }
    {
        A = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
        auto r = so.getOrder(A);
        printvector(r);
    }

    {
        A = {{19, 13}, {16, 9},  {21, 10}, {32, 25}, {37, 4},
             {49, 24}, {2, 15},  {38, 41}, {37, 34}, {33, 6},
             {45, 4},  {18, 18}, {46, 39}, {12, 24}};
        auto r = so.getOrder(A);
        printvector(r);
    }

    return 0;
}