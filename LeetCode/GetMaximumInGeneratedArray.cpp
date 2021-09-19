#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int getMaximumGenerated(int n) {
  if (n < 2) {
    return n;
  }
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  int result = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i / 2];
    if (i % 2) {
      dp[i] += dp[(i + 1) / 2];
    }
    result = max(result, dp[i]);
  }
  return result;
}