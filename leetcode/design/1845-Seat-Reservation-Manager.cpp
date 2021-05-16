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
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> que;

   public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            que.push(i);
        }
    }

    int reserve() {
        if (que.empty())
            return -1;
        auto x = que.top();
        que.pop();
        return x;
    }

    void unreserve(int seatNumber) { que.push(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
int main() {
    // Solution so;
    // [
    //     "SeatManager", "reserve", "reserve", "unreserve", "reserve",
    //     "reserve", "reserve", "reserve", "unreserve"
    // ][[5], [], [], [2], [], [], [], [], [5]];
    int n = 5, r, seatNumber;
    SeatManager* obj = new SeatManager(n);
    r = obj->reserve();
    printf("%d,\n", r);
    r = obj->reserve();
    printf("%d,\n", r);
    seatNumber = 2;
    obj->unreserve(seatNumber);
    for (int i = 0; i < 4; i++) {
        r = obj->reserve();
        printf("%d,\n", r);
    }
    seatNumber = 5;
    obj->unreserve(seatNumber);

    return 0;
}