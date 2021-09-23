#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> buildArray(vector<int> &nums) {
  int n = nums.size();
  int x;
  for (int i = 0; i < n; i++) {
    nums[i] *= n;
  }
  for (int i = 0; i < n; i++) {
    nums[i] += (nums[nums[i] / n] / n);
  }
  for (int i = 0; i < n; i++) {
    nums[i] %= n;
  }
  return nums;
}