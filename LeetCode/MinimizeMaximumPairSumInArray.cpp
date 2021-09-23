#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int minPairSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int result = 0;
  for (int i = 0; i < n / 2; i++) {
    result = max(result, nums[i] + nums[n - i - 1]);
  }
  return result;
}