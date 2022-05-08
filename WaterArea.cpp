#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int waterArea(vector<int> heights) {
  int n = heights.size();
  int leftPtr = 0;
  int rightPtr = n - 1;
  int leftMax = INT_MIN;
  int rightMax = INT_MIN;
  int area = 0;
  while (leftPtr < rightPtr) {
    if (heights[leftPtr] < heights[rightPtr]) {
      leftMax = max(heights[leftPtr], leftMax);
      area += (leftMax - heights[leftPtr]);
      leftPtr++;
    } else {
      rightMax = max(heights[rightPtr], rightMax);
      area += (rightMax - heights[rightPtr]);
      rightPtr--;
    }
  }
  return area;
}
