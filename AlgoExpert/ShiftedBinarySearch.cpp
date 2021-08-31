#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(n)
int shiftedBinarySearch(vector<int> array, int target) {
  int leftPtr = 0;
  int rightPtr = array.size() - 1;
  int midPtr;
  while (leftPtr <= rightPtr) {
    midPtr = leftPtr + (rightPtr - leftPtr) / 2;
    if (array[midPtr] == target) {
      return midPtr;
    } else if (array[leftPtr] <= array[midPtr]) {
      if (target >= array[leftPtr] && target < array[midPtr]) {
        rightPtr = midPtr - 1;
      } else {
        leftPtr = midPtr + 1;
      }
    } else {
      if (target <= array[rightPtr] && target > array[midPtr]) {
        leftPtr = midPtr + 1;
      } else {
        rightPtr = midPtr - 1;
      }
    }
  }
  return -1;
}