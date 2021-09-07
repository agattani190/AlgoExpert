#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int arrayNesting(vector<int> &nums) {
  int result = 0;
  int tempResult = 0;
  for (int i = 0; i < nums.size(); i++) {
    nums[i]++;
    nums[i] *= -1;
  }
  for (int i = 0; i < nums.size(); i++) {
    int index = i;
    tempResult = 0;
    while (true) {
      if (nums[index] < 0) {
        tempResult++;
        nums[index] *= -1;
        index = nums[index] - 1;
      } else {
        result = max(result, tempResult);
        break;
      }
    }
  }
  return result;
}