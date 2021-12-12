#include <vector>
using namespace std;

// Time Complexity: O(n*sum) -> sum is the num of all elements in the set
// Space Complexity: O(n*sum)
bool canPartition(vector<int> &nums) {
  int n = nums.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }
  if (sum % 2) {
    return false;
  }
  sum /= 2;
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      dp[i][j] = dp[i][j] || dp[i - 1][j];
      if (nums[i - 1] <= j) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[n][sum];
}