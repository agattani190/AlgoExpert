#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  int n = array.size();
  vector<int> dp = array;
  int maxSum = array[0];
  int index = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (array[i] > array[j]) {
        dp[i] = max(dp[i], array[i] + dp[j]);
      }
    }
    if (dp[i] > maxSum) {
      maxSum = dp[i];
      index = i;
    }
  }

  vector<int> nums;
  nums.push_back(array[index]);
  int prev = array[index];
  int tempSum = maxSum - array[index--];
  for (; index >= 0; index--) {
    if (dp[index] == tempSum && array[index] < prev) {
      nums.push_back(array[index]);
      prev = array[index];
      tempSum -= array[index];
    }
  }
  int m = nums.size();
  for (int i = 0; i < m / 2; i++) {
    swap(nums[i], nums[m - 1 - i]);
  }

  return {{maxSum}, nums};
}