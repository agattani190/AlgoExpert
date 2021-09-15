#include <vector>
using namespace std;

// Time Complexity: O(height*maxSteps)
// Space Complexity: O(height)
int staircaseTraversal(int height, int maxSteps) {
  vector<int> dp(height + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= height; i++) {
    for (int j = i - 1; j >= 0 && j >= i - maxSteps; j--) {
      dp[i] += dp[j];
    }
  }
  return dp[height];
}
