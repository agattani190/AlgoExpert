#include <vector>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(mn)
vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
  int m = rowSum.size();
  int n = colSum.size();
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = min(rowSum[i], colSum[j]);
      rowSum[i] -= matrix[i][j];
      colSum[j] -= matrix[i][j];
    }
  }
  return matrix;
}