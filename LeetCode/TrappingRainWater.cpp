#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int trap(vector<int> &height) {
  int capacity = 0;
  int leftPtr = 0;
  int rightPtr = height.size() - 1;
  int leftMax = height[leftPtr];
  int rightMax = height[rightPtr];
  while (leftPtr < rightPtr) {
    if (height[leftPtr] < height[rightPtr]) {
      leftMax = max(leftMax, height[leftPtr]);
      capacity += (leftMax - height[leftPtr]);
      leftPtr++;
    } else {
      rightMax = max(rightMax, height[rightPtr]);
      capacity += (rightMax - height[rightPtr]);
      rightPtr--;
    }
  }
  return capacity;
}
