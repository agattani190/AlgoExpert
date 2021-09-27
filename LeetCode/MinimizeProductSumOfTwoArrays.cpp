#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int minProductSum(vector<int> &nums1, vector<int> &nums2) {
  int n = nums1.size();
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += (nums1[i] * nums2[n - i - 1]);
  }
  return result;
}