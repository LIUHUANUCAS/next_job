
/***
[n,n]
代表是数字，相同数字代表同一个颜色


jiayu对所有人说 (9:09 下午)
ABCCA
ACCAD
ADCBA
CDEAB
AAABB

给定一个棋盘(n*n)初始状态，每个坐标值代表其颜色，类似消消乐。
初始的时候会有些相邻的坐标是同色的，相邻是指上下左右四个方向，不可跨出棋盘
现在一个操作，输入为定义为两个坐标，操作是交换这两个坐标的值。这样在棋盘上，与这两个
坐标周边会有相同颜色的，可认为是同一类，或者可消除，类似消消乐，不同点是，可以不用在直线上。
输出：返回能够消除的点的坐标

举一个例子：
假设输入是第二行的CA两个点，交换之后变成

ABCCA
ACCAD
ADCBA -》》》
CDEAB
AAABB


':表示能够消除的坐标位置
AB''A
ACA'D
ADCBA
CDEAB
AAABB

操作：
交换位置


如果写多，读少，例如日志系统如何设计

 - 1,10,9, -> 1,9,10
 - 9,8,10 -> 8,9,10

 - [1,8,9,9,10,10]
 - 【1，9】[1,8,9,9]  + 【10，】[10,10]
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
};

// void dfs(){

// }
string getkey(int a, int b) {
    return to_string(a) + "_" + to_string(b);
}
vector<Node> getList(Node node, int n) {
    int x = node.x;
    int y = node.y;
    // (x +1,y),(x-1,y) ,(x,y-1),(x,y+1)
    vector<Node> res;
    if (x + 1 < n) {
        res.push_back(Node(x + 1, y));
    }
    if (x - 1 >= 0) {
        res.push_back(Node(x - 1, y));
    }
    if (y + 1 < n) {
        res.push_back(Node(x, y + 1));
    }
    if (y - 1 >= 0) {
        res.push_back(Node(x, y - 1));
    }
    return res;
}
int same_color(int x, int y) {
    return x == y;
}
int not_visit(Node x, unordered_map<string, int>& m) {
    string key = getkey(x.x, x.y);
    return m.find(key) == m.end();
}
void swapNode(vector<vector<int>>& board, vector<int>& q) {
    swap(board[q[0]][q[1]], board[q[2]][3]);
}

vector<Node> traversal(vector<vector<int>>& board, int a, int b) {
    // int a = 0, b = 0;  // 交换的点
    Node node = Node(a, b);
    queue<Node> que;
    que.push(node);
    unordered_map<string, int> visit;
    // auto id = get(a, b);
    vector<Node> res;
    // visit[id] = 1;
    while (!que.empty()) {
        Node top = que.front();
        que.pop();
        string id = getkey(top.x, top.y);
        visit[id] = 1;
        res.push_back(top);
        vector<Node> adjlist = getList(top);
        for (Node adj : adjlist) {
            if (not_visit(adj, visit) &&
                same_color(board[adj.x][adj.y], board[node.x][node.y])) {
                que.push(adj);
            }
        }
    }
    return res;
}

void bfs(vector<vector<int>>& board, vector<int>& q) {
    int n = board.size();
    swapNode(board, q);
    // board
    traversal(board, q[0], q[1]);
    traversal(board, q[2], q[3]);
}