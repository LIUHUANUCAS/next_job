#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class MKAverage {
   public:
    deque<int> deq;
    int m, k;
    int sum;
    int size;
    int remainer;
    priority_queue<int, vector<int>, less<int>> top;
    priority_queue<int, vector<int>, greater<int>> bottom;
    MKAverage(int a, int b) {
        m = a;
        k = b;
        sum = 0;
        size = 0;
        remainer = 0;
        printf("m:%d k:%d size:%d,%d\n", m, k, size, sum);
    }

    void addElement(int num) {
        sum += num;
        size++;
        deq.push_back(num);
        // top.push(num);
        if (size == m) {
            for (int i = 0; i < size; i++) {
                top.push(deq[i]);
                bottom.push(deq[i]);
            }
            int d = sum;  // sumk
            while (top.size() > k) {
                d -= top.top();
                top.pop();
            }
            int d2 = sum;  // sumk
            while (bottom.size() > k) {
                d2 -= bottom.top();
                bottom.pop();
            }
            remainer = sum - d - d2;  // remainer
            return;
        }

        // size > m
        top.push(num);
        auto x = top.top();
        top.pop();
        bottom.push(x);
        int y = bottom.top();
        bottom.pop();
        // if (deq.size() == m) {
        //     sum -= deq.front();
        //     deq.pop_front();
        // }
    }

    int calculateMKAverage() {
        printf("size,%d %d ", size, m);
        if (size < m) {
            return -1;
        }

        return remainer / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
int main() {
    int m, k, r;
    m = 3, k = 1;
    MKAverage* obj = new MKAverage(m, k);
    obj->addElement(3);
    obj->addElement(1);
    r = obj->calculateMKAverage();
    cout << r << endl;
    obj->addElement(10);
    r = obj->calculateMKAverage();
    cout << r << endl;

    int x = 5;
    for (int i = 0; i < 3; i++) {
        obj->addElement(x);
    }
    r = obj->calculateMKAverage();
    cout << r << endl;
    return 0;
}