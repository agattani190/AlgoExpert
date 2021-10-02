#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(mn)
string shortestCommonSupersequence(string str1, string str2) {
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
  string lcs = "";
  string result = "";
  int i = m;
  int j = n;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      lcs = str1[i - 1] + lcs;
      i--;
      j--;
    }
  }

  i = 0;
  j = 0;
  for (int k = 0; k < dp[m][n]; k++) {
    while (str1[i] != lcs[k]) {
      result += str1[i++];
    }
    while (str2[j] != lcs[k]) {
      result += str2[j++];
    }
    result += lcs[k];
    i++;
    j++;
  }
  while (i < m) {
    result += str1[i++];
  }
  while (j < n) {
    result += str2[j++];
  }
  return result;
}