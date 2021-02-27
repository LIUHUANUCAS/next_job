#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        stack<int> st;
        int i = 0;
        for (auto d : pushed) {
            st.push(d);
            while (i < n && !st.empty() && popped[i] == st.top()) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};
Solution so;
void test(vector<int>& push, vector<int>& pop) {
    printvector(push);
    printvector(pop);
    auto r = so.validateStackSequences(push, pop);
    cout << r << endl;
}
int main() {
    vector<int> push, pop;
    {
        push = {1, 2, 3, 4, 5};
        pop = {4, 5, 3, 2, 1};
        test(push, pop);
    }

    {
        push = {1, 2, 3, 4, 5};
        pop = {4, 3, 5, 1, 2};
        test(push, pop);
    }
    return 0;
}