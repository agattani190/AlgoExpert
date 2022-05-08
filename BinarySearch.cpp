#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int binarySearch(vector<int> array, int target) {
  int leftPtr = 0;
  int rightPtr = array.size() - 1;
  while (leftPtr <= rightPtr) {
    int mid = (rightPtr + leftPtr) >> 1;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] > target) {
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  return -1;
}