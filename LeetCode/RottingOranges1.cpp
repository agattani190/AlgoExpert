#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int row, int col) {
  int rows = mat.size();
  int columns = mat[0].size();
  int level = 0;
  queue<pair<int, int>> q;
  q.push({row, col});
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      pair<int, int> p = q.front();
      q.pop();
      int r = p.first;
      int c = p.second;
      if (level < dp[r][c]) {
        dp[r][c] = level;
        if (r > 0) {
          if (mat[r - 1][c] == 1) {
            q.push({r - 1, c});
          }
        }
        if (r < rows - 1) {
          if (mat[r + 1][c] == 1) {
            q.push({r + 1, c});
          }
        }
        if (c > 0) {
          if (mat[r][c - 1] == 1) {
            q.push({r, c - 1});
          }
        }
        if (c < columns - 1) {
          if (mat[r][c + 1] == 1) {
            q.push({r, c + 1});
          }
        }
      }
    }
    level++;
  }
}

// Time Complexity: O(rc) -> r,c are height and width of the matrix
// Space Complexity: O((rc)^2)
int orangesRotting(vector<vector<int>> &mat) {
  int rows = mat.size();
  int columns = mat[0].size();
  vector<vector<int>> dp(rows, vector<int>(columns, INT_MAX));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (mat[i][j] == 2) {
        bfs(mat, dp, i, j);
      }
    }
  }
  int result = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (mat[i][j] == 1) {
        result = max(result, dp[i][j]);
      }
    }
  }
  return result == INT_MAX ? -1 : result;
}