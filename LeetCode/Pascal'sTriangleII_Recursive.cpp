#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
vector<int> getRow(int rowIndex) {
  if (rowIndex == 0) {
    return {1};
  }
  vector<int> prevResult = getRow(rowIndex - 1);
  vector<int> result(rowIndex + 1, 1);
  for (int i = 1; i < rowIndex; i++) {
    result[i] = prevResult[i - 1] + prevResult[i];
  }
  return result;
}