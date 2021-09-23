#include <vector>
using namespace std;

// Time Complexity: O(rows*columns)
// Space Complexity: O(rows*columns)
int minPathSum(vector<vector<int>> &grid) {
  int rows = grid.size();
  int columns = grid[0].size();
  vector<vector<int>> dp(rows, vector<int>(columns));
  dp[0][0] = grid[0][0];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i == 0 && j > 0) {
        dp[i][j] = dp[i][j - 1] + grid[i][j];
      } else if (i > 0 && j == 0) {
        dp[i][j] = dp[i - 1][j] + grid[i][j];
      } else if (i > 0 && j > 0) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
  }
  return dp[rows - 1][columns - 1];
}