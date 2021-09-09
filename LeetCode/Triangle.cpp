#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
int minimumTotal(vector<vector<int>> &triangle) {
  vector<vector<int>> dp = triangle;
  int n = triangle.size();
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < triangle[i].size(); j++) {
      dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  return dp[0][0];
}