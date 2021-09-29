#include <climits>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int twoEggDrop(int n) {
  if (n < 3) {
    return n;
  }
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = min(dp[i], max(j, dp[i - j] + 1));
    }
  }
  return dp[n];
}