#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int firstDuplicateValue(vector<int> array) {
  int n = array.size();
  for (int i = 0; i < n; i++) {
    if (array[abs(array[i]) - 1] < 0) {
      return abs(array[i]);
    } else {
      array[abs(array[i]) - 1] *= -1;
    }
  }
  return -1;
}