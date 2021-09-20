#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArray(vector<int> &nums) {
  int n = nums.size();
  int result = *max_element(nums.begin(), nums.end());
  if (result < 1) {
    return result;
  }
  int tempResult = 0;
  for (int i = 0; i < n; i++) {
    tempResult += nums[i];
    result = max(result, tempResult);
    if (tempResult < 0) {
      tempResult = 0;
    }
  }
  return result;
}