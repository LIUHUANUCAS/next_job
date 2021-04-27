#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& A) {
        int l = 0, r = 0;
        unordered_map<int, int> umap;
        int sum = 0;
        int msum = 0;
        int n = A.size();
        while (r < n) {
            auto e = A[r];
            r++;
            sum += e;
            if (umap.find(e) == umap.end()) {  // 没重复
                umap[e] = r - 1;
                msum = max(sum, msum);
            }
            auto idx = umap[e];
            while (idx < r - 1 && l <= idx) {  // 有重复
                sum -= A[l];
                l++;
            }
            umap[e] = r - 1;  // 更新索引位置
        }
        return msum;
    }
};
int main() {
    Solution so;
    vector<int> m = {9, 9, 4, 6, 6, 8, 2, 1, 1};
    {
        m = {5, 2, 1, 2, 5, 2, 1, 2, 5};
        auto r = so.maximumUniqueSubarray(m);
        cout << r << endl;
    }
    {
        m = {4, 2, 4, 5, 6};
        auto r = so.maximumUniqueSubarray(m);
        cout << r << endl;
    }
    return 0;
}