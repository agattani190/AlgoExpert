#include <vector>
using namespace std;

int climbStairsHelper(int n, vector<int> &dp) {
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
  return dp[n];
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int climbStairs(int n) {
  vector<int> dp(n + 1, -1);
  dp[0] = 1;
  dp[1] = 1;
  return climbStairsHelper(n, dp);
}