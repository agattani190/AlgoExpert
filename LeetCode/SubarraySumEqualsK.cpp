#include <unordered_map>
#include <vector>
using namespace std;

// Average Time Complexity: O(n)
// Space Complexity: O(n)
int subarraySum(vector<int> &nums, int k) {
  int n = nums.size();
  int result = 0;
  unordered_map<int, int> dp;
  dp[0] = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (dp.find(sum - k) != dp.end()) {
      result += dp[sum - k];
    }
    dp[sum]++;
  }
  return result;
}