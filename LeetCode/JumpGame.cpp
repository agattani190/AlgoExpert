#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool canJump(vector<int> &nums) {
  int maxReach = 0;
  int i = 0;
  int n = nums.size();
  while (maxReach < n - 1 && i <= maxReach) {
    maxReach = max(maxReach, i + nums[i]);
    i++;
  }
  if (maxReach < n - 1) {
    return false;
  }
  return true;
}