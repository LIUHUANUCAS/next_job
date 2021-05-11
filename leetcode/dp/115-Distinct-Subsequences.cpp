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
    unordered_map<string, int> cache;
    int numDistinct(string s, string t) {
        cache.clear();
        return dyp(s, t);
        // return dfs(s, 0, t, 0);
    }
    int dyp(string& s, string& t) {
        int m = s.size(), n = t.size();
        if (n > m)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j] means s[0,i] vs t[0,j] number of distinct subseq
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {  // equal ,will be s[0,i-1] vs
                                             // t[0,j-1],+  s[0,i-1] vs t[0,j]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {  // not equal must be s[0,i-1] vs t[0,j];
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }

    int dfs(string& s, int i, string& t, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i >= s.size() || j > t.size()) {
            return 0;
        }
        auto key = getkey(i, j);
        if (cache.find(key) != cache.end())
            return cache[key];
        int r = 0;
        if (s[i] == t[j]) {
            r += dfs(s, i + 1, t, j + 1);
        }
        r += dfs(s, i + 1, t, j);
        cache[key] = r;
        return r;
    }
    string getkey(int i, int j) {
        stringstream sst;
        sst << i << "_" << j;
        return sst.str();
    }
};
int main() {
    Solution so;
    string s, t;
    int r;
    {
        s = "rabbbit", t = "rabbit";
        r = so.numDistinct(s, t);
        cout << r << endl;
    }
    {
        s = "babgbag", t = "bag";
        r = so.numDistinct(s, t);
        cout << r << endl;
    }
    {
        s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwx"
            "zwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhy"
            "idevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmp"
            "hyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrf"
            "dghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguw"
            "qijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhn"
            "hryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvw"
            "onalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlk"
            "acnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpg"
            "tgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekje"
            "alvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzcl"
            "idzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvef"
            "ugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajy"
            "zdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyo"
            "zwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyft"
            "jighntqzoo";
        t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
        r = so.numDistinct(s, t);
        cout << r << endl;
    }
    return 0;
}