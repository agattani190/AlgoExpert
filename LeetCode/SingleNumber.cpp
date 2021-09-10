#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int singleNumber(vector<int> &nums) {
  int result = 0;
  for (int i = 0; i < nums.size(); i++) {
    result ^= nums[i];
  }
  return result;
}