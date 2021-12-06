#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int findPeakElement(vector<int> &nums) {
  int n = nums.size();
  if (n == 1 || nums[0] > nums[1]) {
    return 0;
  }
  if (nums[n - 1] > nums[n - 2]) {
    return n - 1;
  }
  int left = 1;
  int right = n - 2;
  int mid;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
      break;
    } else if (nums[mid] < nums[mid - 1]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return mid;
}