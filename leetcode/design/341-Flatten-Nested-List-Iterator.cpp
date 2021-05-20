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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    int i;
    int is_int;
    vector<NestedInteger> next;
    NestedInteger() {}
    NestedInteger(int x) : i(x), is_int(1) {}
    NestedInteger(vector<NestedInteger>& n) : next(n), is_int(0) {}
    bool isInteger() const { return is_int; }

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return i; }

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const { return next; }
};

class NestedIterator {
   public:
    queue<int> que;
    stack<vector<NestedInteger>::iterator> first, last;
    // [[1,1],2,[1,1]]
    NestedIterator(vector<NestedInteger>& B) {
        // A = B;
        first.push(B.begin());
        last.push(B.end());
    }

    int next() {
        move();
        return (first.top()++)->getInteger();
        // return i->getInteger();
    }
    int move() {
        while (!first.empty()) {
            auto cur = first.top();
            auto end = last.top();
            if (cur == end) {
                first.pop();
                last.pop();
            } else {
                if (cur->isInteger()) {
                    return 1;
                } else {
                    // auto is error for reference
                    // auto  list = cur->getList();
                    vector<NestedInteger>& list =
                        (vector<NestedInteger>&)cur->getList();
                    first.top()++;
                    first.push(list.begin());
                    last.push(list.end());
                }
            }
        }
        return 0;
    }
    bool hasNext() {
        return move();
        // return !que.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
    // NestedInteger():
    vector<NestedInteger> first = {NestedInteger(1), NestedInteger(2)};
    NestedInteger second(3);
    vector<NestedInteger> third = {NestedInteger(4), NestedInteger(5)};
    vector<NestedInteger> input = {NestedInteger(first), second,
                                   NestedInteger(third)};
    NestedIterator it(input);
    while (it.hasNext()) {
        cout << it.next() << endl;
    }

    // [[1,2],3,[4,5]]
    return 0;
}