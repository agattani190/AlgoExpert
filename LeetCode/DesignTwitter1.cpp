#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Twitter {
public:
  unordered_map<int, set<int>> graph;
  vector<pair<int, int>> tweets;

  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets.push_back({tweetId, userId});
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> feed;
    int k = 0;
    int n = tweets.size();
    bool isConnected;
    for (int i = n - 1; i >= 0 && k < 10; i--) {
      if (tweets[i].second == userId ||
          graph[userId].find(tweets[i].second) != graph[userId].end()) {
        k++;
        feed.push_back(tweets[i].first);
      }
    }
    return feed;
  }

  void follow(int followerId, int followeeId) {
    graph[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    graph[followerId].erase(followeeId);
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