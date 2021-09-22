#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(mn)
bool isSubsequence(string s, string t) {
  int m = s.size();
  int n = t.size();
  if (m > n) {
    return false;
  }
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
  for (int i = 0; i <= n; i++) {
    dp[0][i] = true;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  return dp[m][n];
}