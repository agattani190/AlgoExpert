#include <vector>
using namespace std;

// Time Complexity: O(nm) -> m is size of denoms
// Space Complexity: O(n)
int minNumberOfdenomsForChange(int n, vector<int> denoms) {
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < denoms.size(); j++) {
      if (i >= denoms[j] && dp[i - denoms[j]] != INT_MAX) {
        dp[i] = min(dp[i], 1 + dp[i - denoms[j]]);
      }
    }
  }
  if (dp[n] == INT_MAX) {
    return -1;
  }
  return dp[n];
}