#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> threeSum(vector<int> &array) {
  vector<vector<int>> result;
  int arraySize = array.size();
  if (arraySize < 3) {
    return result;
  }
  sort(array.begin(), array.end());
  for (int i = 0; i < arraySize - 2; i++) {
    if (i == 0 || array[i] != array[i - 1]) {
      int startPtr = i + 1;
      int endPtr = arraySize - 1;
      int newTarget = 0 - array[i];
      while (startPtr < endPtr) {
        if (array[startPtr] + array[endPtr] == newTarget) {
          result.push_back({array[i], array[startPtr], array[endPtr]});
          while (startPtr < endPtr && array[startPtr] == array[startPtr + 1]) {
            startPtr++;
          }
          while (startPtr < endPtr && array[endPtr] == array[endPtr - 1]) {
            endPtr--;
          }
          startPtr++;
          endPtr--;
        } else if (array[startPtr] + array[endPtr] < newTarget) {
          startPtr++;
        } else {
          endPtr--;
        }
      }
    }
  }
  return result;
}