#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> productExceptSelf(vector<int> &nums) {
  int numsSize = nums.size();
  vector<int> leftProduct(numsSize);
  vector<int> rightProduct(numsSize);
  leftProduct[0] = 1;
  rightProduct[numsSize - 1] = 1;
  for (int i = 1; i < numsSize; i++) {
    leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
    rightProduct[numsSize - i - 1] =
        rightProduct[numsSize - i] * nums[numsSize - i];
  }
  vector<int> result(numsSize);
  for (int i = 0; i < numsSize; i++) {
    result[i] = leftProduct[i] * rightProduct[i];
  }
  return result;
}
