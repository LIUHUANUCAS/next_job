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
class CustomStack {
    deque<int> dque;
    int capacity;

   public:
    CustomStack(int maxSize) { capacity = maxSize; }

    void push(int x) {
        dque.push_back(x);
        if (dque.size() > capacity) {
            dque.pop_back();
        }
    }

    int pop() {
        if (dque.empty())
            return -1;
        int x = dque.back();
        dque.pop_back();
        return x;
    }

    void increment(int k, int val) {
        int n = dque.size();
        for (int i = 0; i < k && i < n; i++) {
            dque[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
int main() {
    int maxSize = 10, x = 1, r = 10, k = 2, val = 10;
    CustomStack* obj = new CustomStack(maxSize);
    obj->push(x);
    r = obj->pop();
    obj->increment(k, val);
    return 0;
}