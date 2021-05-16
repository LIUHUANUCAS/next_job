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
class MyQueue {
    stack<int> first, sec;
    void move() {
        while (!first.empty()) {
            sec.push(first.top());
            first.pop();
        }
    }

   public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { first.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sec.empty()) {
            move();
        }
        auto x = sec.top();
        sec.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (sec.empty())
            move();
        return sec.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return first.empty() && sec.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    int x;
    MyQueue* obj = new MyQueue();
    obj->push(x);
    int param_2 = obj->pop();
    bool param_4 = obj->empty();

    return 0;
}