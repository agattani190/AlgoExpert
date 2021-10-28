#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int removeDuplicates(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  int i = 1;
  int j = 1;
  int k = 1;
  while (i < n) {
    if (nums[i] == nums[i - 1]) {
      i++;
    } else {
      nums[j++] = nums[i++];
      k++;
    }
  }
  return k;
}