#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int twoEggDrop(int n) {
  if (n < 3) {
    return n;
  }
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  int leftPtr, rightPtr, midPtr;
  for (int i = 3; i <= n; i++) {
    leftPtr = 1;
    rightPtr = i - 1;
    while (leftPtr <= rightPtr) {
      midPtr = leftPtr + ((rightPtr - leftPtr) / 2);
      dp[i] = max(midPtr, dp[i - midPtr] + 1);
      if (midPtr == dp[i - midPtr] + 1) {
        break;
      } else if (midPtr < dp[i - midPtr] + 1) {
        leftPtr = midPtr + 1;
      } else {
        rightPtr = midPtr - 1;
      }
    }
  }
  return dp[n];
}