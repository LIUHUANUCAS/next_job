
/**
给定排好序的非负整数数组nums，
请在其中找出不大于c的最大值。
A[i] <= c, [2,3,5,x]
A[i] < c, [2,3,5,x]
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Q: How many legal patterns are there in an Android phone unlock puzzle.
A legal pattern is defined as:
1、A single path that connecting n unique nodes, where 4<=n<=9.
2、Whenever a path
travel through an unconnected node, the node will become connected.
3、A path can
bypass a connected node to connect other unconnected nodes.

存在障碍点列表
1:[3,7,9]
2:[8]
3:[1,7,9]
4:[6]
5:[]
6:[4]
7:[1,3,9]
8:[2]
9:[1,3,7]


vector<pair> p = {
        pair(1, 3, 2),
        pair(1, 7, 4),
        pair(1, 9, 5),
        pair(2, 8, 5),

        pair(3, 1, 2),
        pair(3, 7, 5),
        pair(3, 9, 6),

        pair(4, 6, 5),
        // pair(4, 6, 5),
        pair(6, 4, 5),


        pair(7, 1, 4),
        pair(7, 3, 5),
        pair(7, 9, 8),

        pair(8, 2, 5),

        pair(9, 1, 5),
        pair(9, 7, 8),
        pair(9, 3, 6),

    };



[1,2,3]
[4,5,6]
[7,8,9]

**/
struct Pair {
    int src;   // 起始点
    int dest;  // 目的点
    int obs;   // 障碍点
    // Pair() {}
    Pair(int s, int d, int o) : src(s), dest(d), obs(o) {}
};
struct Puzzle {
    vector<Pair> pairs = {
        // 1
        Pair(1, 3, 2),
        Pair(1, 7, 4),
        Pair(1, 9, 5),
        // 2
        Pair(2, 8, 5),

        // 3
        Pair(3, 1, 2),
        Pair(3, 7, 5),
        Pair(3, 9, 6),

        // 4
        Pair(4, 6, 5),

        // 6
        Pair(6, 4, 5),

        // 7
        Pair(7, 1, 4),
        Pair(7, 3, 5),
        Pair(7, 9, 8),
        // 8
        Pair(8, 2, 5),
        // 9
        Pair(9, 1, 5),
        Pair(9, 7, 8),
        Pair(9, 3, 6),
    };
    vector<unordered_map<int, int>> p;  // 存储起始点，到目标点的，障碍点集合
    const int N = 9;                    // 所有节点数
    const int th = 4;                   // 路径长度阈值
    int pathcount;                      // result
    vector<vector<int>> res;  // 具体的路径

    Puzzle() {
        p = vector<unordered_map<int, int>>(N + 1);
        for (auto e : pairs) {
            int idx = e.src;
            p[idx][e.dest] = e.obs;
        }
    }
    int count() {
        pathcount = 0;
        vector<int> A(N + 1);  // 访问标记数组
        vector<int> onepath;   // 一条具体路径
        for (int i = 1; i <= N; i++) {
            dfs(A, i, 0, onepath);
        }
        // printresult();
        return pathcount;
    }

    void printresult() {
        for (auto e : res) {
            for (auto x : e) {
                printf("%d-", x);
            }
            printf("\n");
        }
    }

    int valid_connect(vector<int>& A, int x, int i) {
        auto r = p[x];
        // printf("%d %d\n", x, i);
        if (r.find(i) == r.end())
            return 1;
        // 障碍点是否被访问，只有障碍点被访问过，才能到达目标节点
        return A[r[i]] < 0;
    }
    int dfs(vector<int>& A, int x, int c, vector<int>& onepath) {
        if (A[x] < 0) {
            return 0;
        }
        A[x] = -1;  // 标记
        onepath.push_back(x);

        if (c >= th) {
            pathcount++;
            res.push_back(onepath);
        }

        for (int i = 1; i <= N; i++) {
            if (i == x || A[i] < 0) {
                continue;
            }
            // x被访问情况下，i不被访问，并且能连接
            if (A[i] > 0 && valid_connect(A, x, i)) {
                dfs(A, i, c + 1, onepath);
            }
        }
        A[x] = 1;  // 移除标记
        onepath.pop_back();
        return 0;
    }
};
int main() {
    Puzzle p;
    int r = p.count();
    cout << r << endl;
}
