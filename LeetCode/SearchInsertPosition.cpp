#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int searchInsert(vector<int> &nums, int target) {
  int leftPtr = 0;
  int rightPtr = nums.size() - 1;
  int result = nums.size();
  while (leftPtr <= rightPtr) {
    int mid = leftPtr + ((rightPtr - leftPtr) >> 1);
    if (nums[mid] >= target) {
      result = mid;
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  return result;
}