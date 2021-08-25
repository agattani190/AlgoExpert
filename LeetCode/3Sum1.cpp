#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> threeSum(vector<int> &array) {
  int targetSum = 0;
  sort(array.begin(), array.end());
  unordered_map<string, int> mp;
  vector<vector<int>> result;
  int arraySize = array.size();
  for (int i = 0; i < arraySize - 2; i++) {
    int startPtr = i + 1;
    int endPtr = arraySize - 1;
    int newTarget = targetSum - array[i];
    while (startPtr < endPtr) {
      if (array[startPtr] + array[endPtr] == newTarget) {
        string s = to_string(array[i]) + to_string(array[startPtr]) +
                   to_string(array[endPtr]);
        if (mp.find(s) == mp.end()) {
          result.push_back({array[i], array[startPtr], array[endPtr]});
          mp[s] = 1;
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
  return result;
}