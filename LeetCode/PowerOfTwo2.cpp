#include <math.h>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
bool isPowerOfTwo(int n) {
  if (n < 1) {
    return false;
  }
  double x = log2(n);
  return x == (int)x;
}