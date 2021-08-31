#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int search(vector<int> &nums, int target) {
  int leftPtr = 0;
  int rightPtr = nums.size() - 1;
  while (leftPtr <= rightPtr) {
    int mid = (rightPtr + leftPtr) >> 1;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  return -1;
}