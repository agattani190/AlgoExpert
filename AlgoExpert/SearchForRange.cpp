#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
vector<int> searchForRange(vector<int> array, int target) {
  int leftPtr = 0;
  int rightPtr = array.size() - 1;
  int lowerBound = -1;
  while (leftPtr <= rightPtr) {
    int mid = (rightPtr + leftPtr) >> 1;
    if (array[mid] == target) {
      lowerBound = mid;
      rightPtr = mid - 1;
    } else if (array[mid] > target) {
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  if (lowerBound == -1) {
    return {-1, -1};
  }
  int upperBound = -1;
  leftPtr = lowerBound;
  rightPtr = array.size() - 1;
  while (leftPtr <= rightPtr) {
    int mid = (rightPtr + leftPtr) >> 1;
    if (array[mid] == target) {
      upperBound = mid;
      leftPtr = mid + 1;
    } else if (array[mid] > target) {
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  return {lowerBound, upperBound};
}