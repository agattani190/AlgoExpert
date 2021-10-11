#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int lengthOfLIS(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, 1);
  int result = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    result = max(result, dp[i]);
  }
  return result;
}