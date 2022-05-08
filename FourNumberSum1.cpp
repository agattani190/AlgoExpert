#include <vector>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n)
vector<vector<int>> threeSum(vector<int> &array, int startPtr, int target) {
  vector<vector<int>> result;
  int arraySize = array.size();
  for (int i = startPtr; i < arraySize - 2; i++) {
    if (i == startPtr || array[i] != array[i - 1]) {
      int startPtr = i + 1;
      int endPtr = arraySize - 1;
      int newTarget = target - array[i];
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

vector<vector<int>> fourSum(vector<int> &array, int target) {
  vector<vector<int>> result;
  int arraySize = array.size();
  if (arraySize < 4) {
    return result;
  }
  sort(array.begin(), array.end());
  for (int i = 0; i < arraySize - 3; i++) {
    if (i == 0 || array[i] != array[i - 1]) {
      vector<vector<int>> temp = threeSum(array, i + 1, target - array[i]);
      for (int index = 0; index < temp.size(); index++) {
        temp[index].push_back(array[i]);
        result.push_back(temp[index]);
      }
    }
  }
  return result;
}