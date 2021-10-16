#include <vector>
using namespace std;

// Time Complexity: O(log(m+n)) -> m and n are sizes of the two arrays
// Space Complexity: O(1)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size();
  int n = nums2.size();

  if (m < n)
    return findMedianSortedArrays(nums2, nums1);

  int low = 0, high = 2 * n;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int mid1 = m + n - mid;

    double left1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
    double left2 = (mid == 0) ? INT_MIN : nums2[(mid - 1) / 2];
    double right1 = (mid1 == m * 2) ? INT_MAX : nums1[(mid1) / 2];
    double right2 = (mid == n * 2) ? INT_MAX : nums2[(mid) / 2];

    if (left1 > right2)
      low = mid + 1;
    else if (left2 > right1)
      high = mid - 1;
    else
      return (max(left1, left2) + min(right1, right2)) / 2;
  }
  return 0;
}