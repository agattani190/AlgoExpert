
#include <vector>
using namespace std;

// Time Complexity: O(knlogn)
// Space Complexity: O(kn)
int superEggDrop(int k, int n) {
  if (k == 1) {
    return n;
  }
  if (n < 3) {
    return n;
  }
  vector<vector<int>> dp(k, vector<int>(n + 1, INT_MAX));
  for (int i = 0; i <= n; i++) {
    dp[0][i] = i;
  }
  int leftPtr, rightPtr, midPtr;
  for (int i = 1; i < k; i++) {
    dp[i][0] = 0;
    dp[i][1] = 1;
    dp[i][2] = 2;
    for (int j = 3; j <= n; j++) {
      leftPtr = 1;
      rightPtr = j - 1;
      while (leftPtr <= rightPtr) {
        midPtr = (leftPtr + rightPtr) / 2;
        dp[i][j] = 1 + max(dp[i - 1][midPtr - 1], dp[i][j - midPtr]);
        if (dp[i - 1][midPtr - 1] == dp[i][j - midPtr]) {
          break;
        } else if (dp[i - 1][midPtr - 1] < dp[i][j - midPtr]) {
          leftPtr = midPtr + 1;
        } else {
          rightPtr = midPtr - 1;
        }
      }
    }
  }
  return dp[k - 1][n];
}