#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
vector<int> getRow(int rowIndex) {
  vector<vector<int>> result(rowIndex + 1);
  for (int i = 0; i <= rowIndex; i++) {
    result[i] = vector<int>(i + 1, 1);
  }
  for (int i = 2; i <= rowIndex; i++) {
    for (int j = 1; j < i; j++) {
      result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    }
  }
  return result[rowIndex];
}