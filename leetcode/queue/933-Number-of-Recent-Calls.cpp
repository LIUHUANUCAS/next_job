#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class RecentCounter {
    queue<int> que;
    const int N = 3000;

   public:
    RecentCounter() {}

    int ping(int t) {
        que.push(t);
        while (!que.empty() && que.front() < t - N) {
            que.pop();
        }
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main() {
    RecentCounter* obj = new RecentCounter();
    int param_1;
    vector<int> A;
    A = {1, 100, 3001, 3002};
    for (auto t : A) {
        auto r = obj->ping(t);
        cout << r << " ";
    }
    cout << endl;
    return 0;
}