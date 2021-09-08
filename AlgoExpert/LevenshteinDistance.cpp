#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(mn) -> m, n are the lenth of the two strings
// Space Complexity: O(1)
int levenshteinDistance(string str1, string str2) {
  int rows = str1.size() + 1;
  int columns = str2.size() + 1;
  vector<vector<int>> dp(rows, vector<int>(columns, INT_MAX));
  for (int i = 0; i < rows; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i < columns; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < columns; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
      }
    }
  }
  return dp[rows - 1][columns - 1];
}