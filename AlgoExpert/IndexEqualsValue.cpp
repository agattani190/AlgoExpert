#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int indexEqualsValue(vector<int> array) {
  int leftPtr = 0;
  int rightPtr = array.size() - 1;
  int midPtr;
  int result = -1;
  while (leftPtr <= rightPtr) {
    midPtr = leftPtr + ((rightPtr - leftPtr) / 2);
    if (array[midPtr] == midPtr) {
      result = midPtr;
      rightPtr = midPtr - 1;
    } else if (array[midPtr] > midPtr) {
      rightPtr = midPtr - 1;
    } else {
      leftPtr = midPtr + 1;
    }
  }
  return result;
}
