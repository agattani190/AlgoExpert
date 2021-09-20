#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxProduct(vector<int> &nums) {
  int n = nums.size();
  int result = nums[0];
  vector<int> dpPositive(n, nums[0]);
  vector<int> dpNegative(n, nums[0]);
  for (int i = 1; i < n; i++) {
    dpPositive[i] = max(
        nums[i], max(nums[i] * dpPositive[i - 1], nums[i] * dpNegative[i - 1]));
    dpNegative[i] = min(
        nums[i], min(nums[i] * dpPositive[i - 1], nums[i] * dpNegative[i - 1]));
    result = max(result, dpPositive[i]);
  }
  return result;
}