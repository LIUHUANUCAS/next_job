#include <cstdio>
#include <iostream>
#include <numeric>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;

int main() {
    struct Data {
        int x, y;
        Data(int i, int j) : x(i), y(j) {}
    };
    vector<Data> A;
    {
        A = {Data(1, 1), Data(2, 2), Data(6, 3), Data(10, 4)};
        auto cmp = [](const Data& a, const Data& b) { return a.x < b.x; };
        auto it = upper_bound(A.begin(), A.end(), Data(6, 1), cmp);
        int r = it->x;
        if (it != A.begin())
            --it;
        printf("%d %d\n", it->x, it->y);
    }

    return 0;
}