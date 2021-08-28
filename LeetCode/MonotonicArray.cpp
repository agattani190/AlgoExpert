#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isMonotonic(vector<int> nums) {
  int numsSize = nums.size();
  int direction = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1]) {
      if (direction == -1) {
        return false;
      }
      direction = 1;
    } else if (nums[i] < nums[i - 1]) {
      if (direction == 1) {
        return false;
      }
      direction = -1;
    }
  }
  return true;
}
