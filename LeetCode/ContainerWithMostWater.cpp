#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxArea(vector<int> &height) {
  int maxArea = 0;
  int leftPtr = 0;
  int rightPtr = height.size() - 1;
  while (leftPtr < rightPtr) {
    maxArea = max(maxArea, (rightPtr - leftPtr) *
                               min(height[leftPtr], height[rightPtr]));
    if (height[leftPtr] < height[rightPtr]) {
      leftPtr++;
    } else {
      rightPtr--;
    }
  }
  return maxArea;
}
