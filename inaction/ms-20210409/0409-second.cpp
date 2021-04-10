
/**
BPE 是一个基于统计的分词方法，算法过程是：
首先将词分成一个一个的字符，然后在词的范围内统计字符对出现的次数，每次将次数最多的字符对保存起来，直到循环次数结束，结束的条件是达到预设的subword词表大小<=
8

例子{ （词和词频）
{'l o w </w>': 5, 'l o w e r </w>': 2, 'n e w e s t </w>': 6, 'w i d e s t
</w>': 3} Subword 大小11: {l, o, w, e, r, </w>, n, s, t, i, d} Iter 1,
最高频连续字节对"e"和"s"出现了6+3=9次，合并成"es"。

输出： {'l o w </w>': 5, 'l o w e r </w>': 2, 'n e w es t </w>': 6, 'w i d es t
</w>': 3} Subword 大小：12 {l, o, w, </w>, e, r, n, es, t, i, d, t}

Iter 2, 最高频连续字节对"es"和"t"出现了6+3=9次, 合并成"est"。
输出： {'l o w </w>': 5, 'l o w e r </w>': 2, 'n e w est </w>': 6, 'w i d est
</w>': 3}

Iter 3, 以此类推，最高频连续字节对为"est"和"</w>" 输出： {'l o w </w>': 5, 'l o
w e r </w>': 2, 'n e w est</w>': 6, 'w i d est</w>': 3}

…..
Iter n, 继续迭代直到达到预设的subword词表大小或下一个最高频的字节对出现频率为1。
}


Dict = {"w o r d </w>": 5, "m a t </w>":3, "w o m a n </w>":4, "w o r k </w>":
5}
*/
#include <algorithm>
#include <iostream>
#include <queue>
// #include <priority_queue>
#include <vector>
using namespace std;
struct queue {
    vector<int> data;
    queue(int n) { data = vector<int>(n, 0); }

    push(int x) {
        data.push_back(x);
        adjust(data.size() - 1);
    }
    pop() {
        // data[0],data.back();
        adjust(0);
    }

    void adjust(int x) {
        int y = x / 2;
        //(x, y)
        // y <=x <= 2*x
    }
};
vector<int> topk(vector<int>& A, int k) {
    priority_queue<int, vector<int>, greater<int>> que;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        que.push(A[i]);
        if (que.size() > k) {
            que.pop();
        }
    }
    vector<int> res;
    while (!que.empty()) {
        auto x = que.top();
        que.pop();
        res.push_back(x);
    }
    return res;
}
void printvector(vector<int>& A) {
    for (auto e : A) {
        cout << e << " ";
    }
    cout << endl;
}
int main() {
    vector<int> A;
    int k;
    {
        A = {5, 2, 3, 5};
        k = 2;
        auto r = topk(A, k);
        printvector(r);
    }
    {
        A = {5, 2, 3, -1};
        k = 3;
        auto r = topk(A, k);
        printvector(r);
    }
}
