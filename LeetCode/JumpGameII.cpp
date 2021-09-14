#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int jump(vector<int> &array) {
  int n = array.size();
  vector<int> dp(n, INT_MAX);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n && j <= i + array[i]; j++) {
      if (dp[j] != INT_MAX) {
        dp[i] = min(dp[j] + 1, dp[i]);
      }
    }
  }
  return dp[0];
}