#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isMonotonic(vector<int> array) {
  int arraySize = array.size();
  int direction = 0;
  for (int i = 1; i < arraySize; i++) {
    if (array[i] > array[i - 1]) {
      if (direction == -1) {
        return false;
      }
      direction = 1;
    } else if (array[i] < array[i - 1]) {
      if (direction == 1) {
        return false;
      }
      direction = -1;
    }
  }
  return true;
}
