#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int removeDuplicates(vector<int> &nums) {
  int n = nums.size();
  if (n < 2) {
    return n;
  }
  int i = 1;
  int j = 1;
  int count = 1;
  while (i < n) {
    if (nums[i] == nums[i - 1]) {
      count++;
    } else {
      count = 1;
    }
    if (count < 3) {
      nums[j++] = nums[i];
    }
    i++;
  }
  return j;
}