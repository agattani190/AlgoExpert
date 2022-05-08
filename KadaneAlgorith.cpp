#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int kadanesAlgorithm(vector<int> array) {
  int result = 0;
  int tempResult = 0;
  int arraySize = array.size();
  for (int i = 0; i < arraySize; i++) {
    if (array[i] < 0) {
      result = max(result, tempResult);
    }
    tempResult += array[i];
    if (tempResult < 0) {
      tempResult = 0;
    }
  }
  result = max(result, tempResult);

  if (result == 0) {
    result = INT_MIN;
    for (int i = 0; i < arraySize; i++) {
      result = max(result, array[i]);
    }
  }
  return result;
}
