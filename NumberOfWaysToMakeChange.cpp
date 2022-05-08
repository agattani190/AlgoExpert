#include <vector>
using namespace std;

// Time Complexity: O(nd) - d is the size of denoms
// Space Complexity: O(n)
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < denoms.size(); i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= denoms[i]) {
        dp[j] += dp[j - denoms[i]];
      }
    }
  }
  return dp[n];
}
