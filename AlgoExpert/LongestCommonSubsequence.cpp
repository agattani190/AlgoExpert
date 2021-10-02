#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(mn)
vector<char> longestCommonSubsequence(string str1, string str2) {
  int m = str1.size();
  int n = str2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int count = dp[m][n];
  vector<char> result(count);
  int i = m;
  int j = n;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      result[--count] = str1[i - 1];
      i--;
      j--;
    }
  }
  return result;
}
