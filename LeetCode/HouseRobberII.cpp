#include <vector>
using namespace std;

int robHelper(vector<int> &nums, int start, int end);

// Time Complexity: O(n)
// Space Complexity: O(1)
int rob(vector<int> &nums) {
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  return max(robHelper(nums, 0, n - 1), robHelper(nums, 1, n));
}

int robHelper(vector<int> &nums, int start, int end) {
  int a = 0;
  int b = nums[start];
  int c;
  int result = nums[start];
  for (int i = start + 1; i < end; i++) {
    c = max(b, a + nums[i]);
    result = max(result, c);
    a = b;
    b = c;
  }
  return result;
}