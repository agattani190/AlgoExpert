#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(sz*m*n + sz*strSize) -> sz is length of strs
// strSize is the max length of a string in strs
// Space Complexity: O(sz*m*n)
int findMaxForm(vector<string> &strs, int m, int n) {
  int sz = strs.size();
  vector<pair<int, int>> count(sz);
  int strSize;
  for (int i = 0; i < sz; i++) {
    strSize = strs[i].size();
    for (auto s : strs[i]) {
      if (s == '0') {
        strSize--;
      }
    }
    count[i] = {strs[i].size() - strSize, strSize};
    // cout << count[i].first << " " << count[i].second << "\n";
  }

  vector<vector<vector<int>>> dp(
      sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
  for (int i = 1; i <= sz; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = dp[i - 1][j][k];
        if (count[i - 1].first <= j && count[i - 1].second <= k) {
          dp[i][j][k] = max(
              dp[i][j][k],
              1 + dp[i - 1][j - count[i - 1].first][k - count[i - 1].second]);
        }
      }
    }
  }
  return dp[sz][m][n];
}