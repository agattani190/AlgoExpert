#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int minStartValue(vector<int> &nums) {
  int n = nums.size();
  int totalSum = 0;
  int minStepSum = 0;
  for (int i = 0; i < n; i++) {
    totalSum += nums[i];
    minStepSum = min(minStepSum, totalSum);
  }
  return minStepSum > 0 ? 0 : minStepSum * -1 + 1;
}