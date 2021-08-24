#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
  vector<vector<int>> result;
  int arraySize = array.size();
  for (int i = 0; i < array.size() - 2; i++) {
    int startPtr = i + 1;
    int endPtr = arraySize - 1;
    int newTarget = targetSum - array[i];
    while (startPtr < endPtr) {
      if (array[startPtr] + array[endPtr] == newTarget) {
        result.push_back({array[i], array[startPtr], array[endPtr]});
        startPtr++;
        endPtr--;
      } else if (array[startPtr] + array[endPtr] < newTarget) {
        startPtr++;
      } else {
        endPtr--;
      }
    }
  }
  return result;
}