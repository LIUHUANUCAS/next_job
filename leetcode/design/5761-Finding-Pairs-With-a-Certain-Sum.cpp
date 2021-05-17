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
class FindSumPairs {
    vector<int> A, B;
    unordered_map<int, int> m;  // val count

   public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        A = nums1;
        sort(A.begin(), A.end());
        B = nums2;
        int n = nums2.size();
        for (auto e : nums2) {
            m[e]++;
        }
    }

    void add(int index, int val) {
        m[B[index]]--;
        B[index] += val;
        m[B[index]]++;
    }

    int count(int tot) {
        int c = 0;
        for (auto n : A) {
            if (m.find(tot - n) != m.end()) {
                c += m[tot - n];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
int main() {
    vector<int> nums1, nums2;
    FindSumPairs* obj = new FindSumPairs(nums1, nums2);
    return 0;
}