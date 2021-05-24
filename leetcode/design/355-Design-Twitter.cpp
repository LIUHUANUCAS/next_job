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
class Twitter {
    unordered_map<int, deque<pair<int, int>>> post;  // user_id->{post_id}
    unordered_map<int, unordered_set<int>>
        follower;  // user_id -> {follower_id}
    int time;

   public:
    /** Initialize your data structure here. */
    Twitter() : time(0) {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time++, tweetId});
        follower[userId].insert(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto idlist = follower[userId];
        if (idlist.empty())
            return {};
        auto cmp = [](const pair<int, int>& A, const pair<int, int>& B) {
            return A.first > B.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            que(cmp);
        // priority_queue<pair<int, int>> que;
        int N = 10;
        for (auto id : idlist) {
            auto postlist = post[id];
            for (auto postid : postlist) {
                que.push(postid);
                if (que.size() > N) {
                    que.pop();
                }
            }
        }
        vector<int> res;
        while (!que.empty()) {
            auto x = que.top();
            que.pop();
            res.push_back(x.second);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (follower.find(followerId) == follower.end())
            return;
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main() {
    Twitter* obj = new Twitter();
    int userId = 1;
    vector<int> postidlist = {5, 3, 101, 13, 10, 2, 94, 505, 333, 22, 11};
    for (auto tweetId : postidlist)
        obj->postTweet(userId, tweetId);
    auto list = obj->getNewsFeed(userId);
    printvector(list);

    return 0;
}