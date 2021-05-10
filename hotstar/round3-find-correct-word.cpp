#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 *
 给定一个单词列表，有些单词出现了部分的错误，例如单词author，变成了athuor。
 变动中有些第一个字母和最后一个字母没有发生变化
 例如a[utho]r -> a[thuo]r,
 只有中括号内的部分字母发生变化，给定一个词典找出这些错误的单词。
 如果找不到，输出原来的单词。
 * **/
struct Solution {
    vector<string> find_words(vector<string>& word_list, vector<string>& dict) {
        unordered_map<string, vector<string>> m;
        for (auto& w : dict) {
            if (w.size() > 2) {
                string t(w);
                sort(t.begin() + 1, t.end() - 1);
                m[t].push_back(w);
            }
        }
        vector<string> list;
        for (auto& w : word_list) {
            string t(w);
            if (w.size() > 2) {
                sort(t.begin() + 1, t.end() - 1);
            }
            string r(w);
            if (m.find(t) != m.end()) {
                r = find_nearest_word(t, m[t]);
            }
            list.push_back(r);
        }
        return list;
    }
    string find_nearest_word(string& w, vector<string>& list) {
        return list.back();
    }
};
int main() {
    Solution so;
    return 0;
}
