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
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> que;
    int n;

   public:
    KthLargest(int k, vector<int>& A) {
        n = k;
        for (auto e : A) {
            que.push(e);
            if (que.size() > k) {
                que.pop();
            }
        }
    }

    int add(int val) {
        que.push(val);
        if (que.size() > n) {
            que.pop();
        }

        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main() {
    int k = 3, r;
    vector<int> A = {4, 5, 8, 2};
    KthLargest kthLargest(k, A);
    r = kthLargest.add(3);  // return 4
    cout << r << endl;
    r = kthLargest.add(5);  // return 5
    cout << r << endl;

    r = kthLargest.add(10);  // return 5
    cout << r << endl;

    r = kthLargest.add(9);  // return 8
    cout << r << endl;

    r = kthLargest.add(4);  // return 8
    cout << r << endl;

    return 0;
}