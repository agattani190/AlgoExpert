#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
void moveZeroes(vector<int> &nums) {
  int index = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      nums[index++] = nums[i];
    }
  }
  while (index < nums.size()) {
    nums[index++] = 0;
  }
}