#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    const static int N = 26;
    // unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
    int array[N] = {0};
    int maxVowels(string s, int k) {
        int n = s.size();
        string str("aeiou");
        int j = 0, i = 0, c = 0, mlen = 0;
        for (auto c : str) {
            array[c - 'a'] = 1;
        }
        for (i = 0; i < k; i++) {
            c += (array[s[i] - 'a']);
        }
        mlen = c;
        for (; i < n; i++, j++) {
            c += (array[s[i] - 'a']);
            c -= (array[s[j] - 'a']);
            mlen = max(c, mlen);
        }
        return mlen;
    }
};
int main() {
    Solution so;
    string s;
    int k, r;
    {
        s = "abciiidef", k = 3;
        r = so.maxVowels(s, k);
        cout << r << endl;
    }
    {
        s = "aeiou", k = 2;
        r = so.maxVowels(s, k);
        cout << r << endl;
    }

    {
        s = "leetcode", k = 3;
        r = so.maxVowels(s, k);
        cout << r << endl;
    }

    {
        s = "rhythms", k = 4;
        r = so.maxVowels(s, k);
        cout << r << endl;
    }
    {
        s = "tryhard", k = 4;
        r = so.maxVowels(s, k);
        cout << r << endl;
    }

    return 0;
}