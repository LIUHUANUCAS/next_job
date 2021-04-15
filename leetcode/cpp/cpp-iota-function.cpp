#include <cstdio>
#include <iostream>
#include <numeric>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;

//  iota(_ForwardIterator __first, _ForwardIterator __last, _Tp __value_)
// 451 {
// 452     for (; __first != __last; ++__first, (void) ++__value_)
// 453         *__first = __value_;
// 454 }
int main() {
    vector<int> A;
    {
        A = {-1, -2, -3, -4};
        iota(A.begin(), A.end(), 10);
        printvector(A);
    }
    {
        A = vector<int>(10);
        iota(A.begin(), A.end(), 1);
        printvector(A);
    }
    return 0;
}