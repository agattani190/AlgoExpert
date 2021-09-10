#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
bool isPowerOfTwo(int n) {
  int i = 1;
  while (i < n and i <= INT_MAX / 2) {
    i *= 2;
  }
  if (i == n) {
    return true;
  }
  return false;
}