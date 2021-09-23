#include <vector>
using namespace std;

// Time Complexity: O(rows*columns)
// Space Complexity: O(rows*columns)
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  if (obstacleGrid[0][0]) {
    return 0;
  }
  int rows = obstacleGrid.size();
  int columns = obstacleGrid[0].size();
  vector<vector<int>> dp(rows, vector<int>(columns, 1));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (obstacleGrid[i][j]) {
        dp[i][j] = 0;
      } else {
        if (i == 0 && j > 0) {
          dp[i][j] = dp[i][j - 1];
        } else if (i > 0 && j == 0) {
          dp[i][j] = dp[i - 1][j];
        } else if (i > 0 && j > 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
  }
  return dp[rows - 1][columns - 1];
}