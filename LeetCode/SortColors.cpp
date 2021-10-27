#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
void sortColors(vector<int> &nums) {
  int n = nums.size();
  vector<int> count(3, 0);
  for (int i = 0; i < n; i++) {
    count[nums[i]]++;
  }
  int i = 0;
  while (count[0]--) {
    nums[i++] = 0;
  }
  while (count[1]--) {
    nums[i++] = 1;
  }
  while (count[2]--) {
    nums[i++] = 2;
  }
}