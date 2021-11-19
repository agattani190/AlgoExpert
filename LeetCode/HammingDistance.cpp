#include <vector>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
int hammingDistance(int x, int y) {
  int result = 0;
  int z = x ^ y;
  while (z > 0) {
    result += (z % 2);
    z /= 2;
  }
  return result;
}