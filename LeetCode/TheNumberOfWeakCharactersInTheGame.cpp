#include <vector>
using namespace std;

// Store pairs with strongest defence first if attack is same
static bool comp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int numberOfWeakCharacters(vector<vector<int>> &properties) {
  int result = 0;
  int maxDefence = INT_MIN;
  vector<pair<int, int>> pi;
  for (auto c : properties)
    pi.push_back({c[0], c[1]});
  sort(pi.begin(), pi.end(), comp);
  for (int i = pi.size() - 1; i >= 0; i--) {
    if (pi[i].second < maxDefence) {
      result++;
    }
    maxDefence = max(maxDefence, pi[i].second);
  }
  return result;
}