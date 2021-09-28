#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> sortArrayByParityII(vector<int> &nums) {
  int n = nums.size();
  int j = 1;
  for (int i = 0; i < n; i += 2) {
    if ((i + nums[i]) % 2) {
      while ((j + nums[j]) % 2 == 0) {
        j += 2;
      }
      swap(nums[i], nums[j]);
    }
  }
  return nums;
}