#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProduct(vector<int> &nums) {
  int n = nums.size();
  int result = nums[0];
  int maxPosResult = nums[0];
  int minNegResult = nums[0];
  int temp;
  for (int i = 1; i < n; i++) {
    temp = maxPosResult;
    maxPosResult = max(nums[i], max(nums[i] * temp, nums[i] * minNegResult));
    minNegResult = min(nums[i], min(nums[i] * temp, nums[i] * minNegResult));
    result = max(result, maxPosResult);
  }
  return result;
}