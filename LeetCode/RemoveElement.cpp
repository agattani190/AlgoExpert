#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int removeElement(vector<int> &nums, int val) {
  int numsSize = nums.size();
  int leftPtr = 0;
  int rightPtr = numsSize - 1;
  while (leftPtr < rightPtr) {
    if (nums[rightPtr] != val) {
      if (nums[leftPtr] == val) {
        swap(nums[leftPtr], nums[rightPtr]);
        rightPtr--;
      }
      leftPtr++;
    } else {
      rightPtr--;
    }
  }

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == val) {
      return i;
    }
  }
  return numsSize;
}