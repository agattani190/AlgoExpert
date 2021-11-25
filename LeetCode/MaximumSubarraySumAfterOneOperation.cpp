#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxSumAfterOperation(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp1(n), dp2(n);
  dp1[0] = nums[0];
  dp2[0] = nums[0] * nums[0];
  for (int i = 1; i < n; i++) {
    dp1[i] = nums[i];
    dp2[i] = nums[i] * nums[i];
    dp1[i] = max(dp1[i], nums[i] + dp1[i - 1]);
    dp2[i] = max(max(dp2[i], dp2[i] + dp1[i - 1]), nums[i] + dp2[i - 1]);
  }
  return *max_element(dp2.begin(), dp2.end());
}