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
class OrderedStream {
   public:
    vector<string> strs;
    int idx = 0;
    OrderedStream(int n) : strs(n) {}

    vector<string> insert(int idKey, string value) {
        int n = strs.size();
        strs[idKey - 1] = value;
        int pre = idx;
        vector<string> list;
        for (; idx < n && !strs[idx].empty(); idx++) {
            list.push_back(strs[idx]);
        }
        return list;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
int main() {
    int n = 5;
    vector<string> res;
    OrderedStream os(n);
    res = os.insert(3, "ccccc");  // Inserts (3, "ccccc"), returns [].
    printvector(res);
    res = os.insert(1, "aaaaa");  // Inserts (1, "aaaaa"), returns ["aaaaa"].
    printvector(res);

    res = os.insert(
        2, "bbbbb");  // Inserts (2, "bbbbb"), returns ["bbbbb", "ccccc"].
    printvector(res);

    res = os.insert(5, "eeeee");  // Inserts (5, "eeeee"), returns [].
    printvector(res);

    res = os.insert(
        4, "ddddd");  // Inserts (4, "ddddd"), returns ["ddddd", "eeeee"].
                      // Concatentating all the chunks returned:
    printvector(res);
    // [] + ["aaaaa"] + ["bbbbb", "ccccc"] + [] + ["ddddd", "eeeee"] = ["aaaaa",
    // "bbbbb", "ccccc", "ddddd", "eeeee"] The resulting order is the same as
    // the order above.
    return 0;
}