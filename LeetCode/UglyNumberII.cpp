#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int nthUglyNumber(int n) {
  vector<int> dp(n + 1);
  int u2 = 0;
  int u3 = 0;
  int u5 = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = min({2 * dp[u2], 3 * dp[u3], 5 * dp[u5]});
    if (dp[i] == 2 * dp[u2]) {
      u2++;
    }
    if (dp[i] == 3 * dp[u3]) {
      u3++;
    }
    if (dp[i] == 5 * dp[u5]) {
      u5++;
    }
  }
  return dp[n - 1];
}