#include <vector>
using namespace std;

// Time Complexity: O(n^4)
// Space Complexity: O(1)
int countQuadruplets(vector<int> &nums) {
  int result = 0;
  int arraySize = nums.size();
  for (int i = 0; i < arraySize - 3; i++) {
    for (int j = i + 1; j < arraySize - 2; j++) {
      for (int k = j + 1; k < arraySize - 1; k++) {
        for (int l = k + 1; l < arraySize; l++) {
          if (nums[i] + nums[j] + nums[k] == nums[l]) {
            result++;
          }
        }
      }
    }
  }
  return result;
}