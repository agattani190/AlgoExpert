#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxTurbulenceSize(vector<int> &arr) {
  int n = arr.size();
  int result = 1;
  int index = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] == arr[i]) {
      result = max(result, i - index);
      index = i;
    } else if (i == n - 1 || ((arr[i - 1] > arr[i] && arr[i] > arr[i + 1]) ||
                              (arr[i + 1] > arr[i] && arr[i] > arr[i - 1]))) {
      result = max(result, i - index + 1);
      index = i;
    }
  }
  return result;
}
