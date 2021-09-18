#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> countBits(int n) {
  if (n == 0) {
    return {0};
  }
  vector<int> result(n + 1, 0);
  result[1] = 1;
  int powerOfTwo = 2;
  int previousPowerOfTwo;
  for (int i = 2; i <= n; i++) {
    if (i == powerOfTwo) {
      previousPowerOfTwo = powerOfTwo;
      powerOfTwo *= 2;
      result[i] = 1;
    } else {
      result[i] = 1 + result[i - previousPowerOfTwo];
    }
  }
  return result;
}