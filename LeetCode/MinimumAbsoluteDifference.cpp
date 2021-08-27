#include <math.h>
#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
  vector<vector<int>> result;
  int arrSize = arr.size();
  int minAbsValue = INT_MAX;
  sort(arr.begin(), arr.end());
  for (int i = 1; i < arrSize; i++) {
    minAbsValue = min(minAbsValue, arr[i] - arr[i - 1]);
  }
  for (int i = 1; i < arrSize; i++) {
    if (arr[i] - arr[i - 1] == minAbsValue) {
      result.push_back({arr[i - 1], arr[i]});
    }
  }
  return result;
}