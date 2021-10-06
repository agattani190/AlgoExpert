#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
string longestPalindromicSubstring(string s) {
  int n = s.size();
  int result = INT_MIN;
  int start = -1, end = -1;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      for (int k = j; k < j + i; k++) {
        if (j + 1 <= k - 1) {
          dp[j][k] = dp[j + 1][k - 1] && s[j] == s[k];
        } else {
          dp[j][k] = s[j] == s[k];
        }
        if (dp[j][k] && k - j + 1 > result) {
          result = k - j + 1;
          start = j;
          end = k;
        }
      }
    }
  }
  return s.substr(start, end - start + 1);
}
