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
    string s;
    {
        s = "1234";
        string t(s.cbegin(), s.cend());
        cout << t << endl;
    }
    return 0;
}