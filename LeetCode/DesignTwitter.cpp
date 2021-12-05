#include <unordered_map>
#include <vector>
using namespace std;

class Twitter {
public:
  unordered_map<int, vector<int>> graph;
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
      if (tweets[i].second == userId) {
        k++;
        feed.push_back(tweets[i].first);
      } else {
        isConnected = false;
        for (int j = 0; j < graph[userId].size(); j++) {
          if (graph[userId][j] == tweets[i].second) {
            isConnected = true;
            break;
          }
        }
        if (isConnected) {
          k++;
          feed.push_back(tweets[i].first);
        }
      }
    }
    return feed;
  }

  void follow(int followerId, int followeeId) {
    if (graph.find(followerId) == graph.end()) {
      graph[followerId] = {};
    }
    graph[followerId].push_back(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    int i = 0;
    while (i < graph[followerId].size()) {
      if (graph[followerId][i] == followeeId) {
        break;
      }
      i++;
    }
    if (i < graph[followerId].size()) {
      graph[followerId].erase(graph[followerId].begin() + i);
    }
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