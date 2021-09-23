#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
  int n = grid.size();
  vector<int> rowMax(n, -1);
  vector<int> columnMax(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rowMax[i] = max(rowMax[i], grid[i][j]);
      columnMax[i] = max(columnMax[i], grid[j][i]);
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result += (min(rowMax[i], columnMax[j]) - grid[i][j]);
    }
  }
  return result;
}