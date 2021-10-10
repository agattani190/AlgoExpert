#include <vector>
using namespace std;

// Time Complexity: O(m + n) -> m and n are sizes of the two arrays
// Space Complexity: O(m + n)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size();
  int n = nums2.size();
  vector<int> mergedArray(m + n);
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;
  while (i < m && j < n) {
    if (nums1[i] <= nums2[j]) {
      mergedArray[k++] = nums1[i++];
    } else {
      mergedArray[k++] = nums2[j++];
    }
  }
  while (i < m) {
    mergedArray[k++] = nums1[i++];
  }
  while (j < n) {
    mergedArray[k++] = nums2[j++];
  }
  if ((m + n) % 2) {
    return mergedArray[(m + n) / 2];
  }
  return ((double)mergedArray[(m + n) / 2] + mergedArray[(m + n - 1) / 2]) / 2;
}