#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int rob(vector<int> &nums) {
  int n = nums.size();
  int pPrev = 0;
  int prev = nums[0];
  int curr;
  int result = nums[0];
  for (int i = 1; i < n; i++) {
    curr = max(prev, pPrev + nums[i]);
    result = max(result, curr);
    pPrev = prev;
    prev = curr;
  }
  return result;
}