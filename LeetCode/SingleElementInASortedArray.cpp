#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int singleNonDuplicate(vector<int> &nums) {
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int mid;
  while (left <= right) {
    if (left == right) {
      break;
    }
    mid = left + (right - left) / 2;
    if (nums[mid] == nums[mid - 1]) {
      if ((mid - left) % 2) {
        left = mid + 1;
      } else {
        right = mid - 2;
      }
    } else if (nums[mid] == nums[mid + 1]) {
      if ((right - mid) % 2) {
        right = mid - 1;
      } else {
        left = mid + 2;
      }
    } else {
      return nums[mid];
    }
  }
  return nums[left];
}