#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int totalHammingDistance(vector<int> &nums) {
  int n = nums.size();
  vector<int> bitsCount(32, 0);
  int j, k;
  for (int i = 0; i < n; i++) {
    j = 0;
    k = nums[i];
    while (k > 0) {
      bitsCount[j++] += (k % 2);
      k /= 2;
    }
  }
  int result = 0;
  for (int i = 0; i < 32; i++) {
    result += (bitsCount[i] * (n - bitsCount[i]));
  }
  return result;
}