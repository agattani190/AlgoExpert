#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sortedSquares(vector<int> &nums) {
  int leftPtr = 0;
  int rightPtr = nums.size() - 1;
  vector<int> squaredArray(nums.size());
  int index = rightPtr;
  while (leftPtr <= rightPtr) {
    if (abs(nums[leftPtr]) >= abs(nums[rightPtr])) {
      squaredArray[index--] = nums[leftPtr] * nums[leftPtr];
      leftPtr++;
    } else {
      squaredArray[index--] = nums[rightPtr] * nums[rightPtr];
      rightPtr--;
    }
  }
  return squaredArray;
}