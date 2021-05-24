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
class TweetCounts {
    // unordered_map<string, vector<int>> post;
    unordered_map<string, multiset<int>> post;

   public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        post[tweetName].insert(time);
        // post[tweetName].push_back(time);
        // sort(post[tweetName].begin(), post[tweetName].end());
    }

    vector<int> getTweetCountsPerFrequency(string freq,
                                           string tweetName,
                                           int startTime,
                                           int endTime) {
        int size = 0;
        int step = getstep(freq);
        int x = (endTime - startTime) / step;
        auto list = post[tweetName];
        auto it = lower_bound(list.begin(), list.end(), startTime);
        vector<int> res(x + 1, 0);
        for (; it != list.end() && *it <= endTime; ++it) {
            res[(*it - startTime) / step]++;
        }

        return res;
    }
    int getstep(string freq) {
        if (freq == "hour") {
            return 60 * 60;
        } else if (freq == "day") {
            return 86400;
        }
        return 60;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
int main() {
    // Solution so;
    TweetCounts* obj = new TweetCounts();

    return 0;
}