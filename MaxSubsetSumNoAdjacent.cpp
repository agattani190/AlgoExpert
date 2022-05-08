#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxSubsetSumNoAdjacent(vector<int> array) {
  int n = array.size();
  if (n == 0) {
    return 0;
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = array[0];
  for (int i = 2; i <= n; i++) {
    dp[i] = max(dp[i - 2] + array[i - 1], dp[i - 1]);
  }
  return dp[n];
}