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
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int array[26] = {0};
        for (auto c : magazine)
            array[c - 'a']++;
        for (auto c : ransomNote)
            if (--array[c - 'a'] < 0)
                return 0;
        return 1;
    }
};
int main() {
    Solution so;
    string ransomNote, magazine;
    int r = 0;
    {
        ransomNote = "a", magazine = "b";
        r = so.canConstruct(ransomNote, magazine);
        cout << r << endl;
    }
    {
        ransomNote = "aa", magazine = "ab";
        r = so.canConstruct(ransomNote, magazine);
        cout << r << endl;
    }
    {
        ransomNote = "aa", magazine = "aab";
        r = so.canConstruct(ransomNote, magazine);
        cout << r << endl;
    }
    return 0;
}