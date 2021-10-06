#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
string longestPalindrome(string s) {
  int n = s.size();
  int result = INT_MIN;
  int start = -1, end = -1;
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      int k = j + i - 1;
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
  return s.substr(start, end - start + 1);
}