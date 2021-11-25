#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxAbsoluteSum(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp1(n);
  vector<int> dp2(n);
  dp1[0] = nums[0];
  dp2[0] = nums[0];
  for (int i = 1; i < n; i++) {
    dp1[i] = max(nums[i], nums[i] + dp1[i - 1]);
    dp2[i] = min(nums[i], nums[i] + dp2[i - 1]);
  }
  return max(*max_element(dp1.begin(), dp1.end()),
             abs(*min_element(dp2.begin(), dp2.end())));
}