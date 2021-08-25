#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(n)
int search(vector<int> &nums, int target) {
  int leftPtr = 0;
  int rightPtr = nums.size() - 1;
  int midPtr;
  while (leftPtr <= rightPtr) {
    midPtr = leftPtr + (rightPtr - leftPtr) / 2;
    if (nums[midPtr] == target) {
      return midPtr;
    } else if (nums[leftPtr] <= nums[midPtr]) {
      if (target >= nums[leftPtr] && target < nums[midPtr]) {
        rightPtr = midPtr - 1;
      } else {
        leftPtr = midPtr + 1;
      }
    } else {
      if (target <= nums[rightPtr] && target > nums[midPtr]) {
        leftPtr = midPtr + 1;
      } else {
        rightPtr = midPtr - 1;
      }
    }
  }
  return -1;
}