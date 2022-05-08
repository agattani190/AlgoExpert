#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool hasSingleCycle(vector<int> array) {
  int counter = 1;
  int arraySize = array.size();
  for (int i = 0; i < arraySize; i++) {
    array[i] %= arraySize;
    array[i] += arraySize;
    array[i] %= arraySize;
  }
  int index = 0;
  while (counter < arraySize) {
    index = (index + array[index]) % arraySize;
    counter++;
    if (index == 0) {
      return false;
    }
  }
  index = (index + array[index]) % arraySize;
  if (index == 0) {
    return true;
  } else {
    return false;
  }
}
