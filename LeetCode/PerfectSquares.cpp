#include <math.h>
#include <vector>
using namespace std;

// Time Complexity: O(nsqrt(n))
// Space Complexity: O(n)
int numSquares(int n) {
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i * i <= n; i++) {
    dp[i * i] = 1;
  }
  int sr;
  for (int i = 2; i <= n; i++) {
    if (dp[i] == 1) {
      continue;
    } else {
      sr = sqrt(i);
      dp[i] = 1 + dp[i - sr * sr];
      for (int j = 1; j < sr; j++) {
        dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
      }
    }
  }
  return dp[n];
}