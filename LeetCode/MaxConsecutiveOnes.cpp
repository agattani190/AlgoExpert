#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int findMaxConsecutiveOnes(vector<int> &nums) {
  int tempCount = 0;
  int result = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i]) {
      tempCount++;
    } else {
      result = max(result, tempCount);
      tempCount = 0;
    }
  }
  result = max(result, tempCount);
  return result;
}