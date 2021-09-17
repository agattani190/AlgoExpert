#include <vector>
using namespace std;

// Time Complexity: O(n1log(n1) + n2log(n2) + n1log(n2))
// Space Complexity: O(1)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int index = 0;
  vector<int> result;
  int n1 = nums1.size();
  int n2 = nums2.size();
  int temp;
  for (int i = 0; i < n1; i++) {
    temp = lower_bound(nums2.begin() + index, nums2.end(), nums1[i]) -
           nums2.begin();
    if (temp != n2 && nums1[i] == nums2[temp]) {
      index = temp + 1;
      result.push_back(nums1[i]);
    }
  }
  return result;
}