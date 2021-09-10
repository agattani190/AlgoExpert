#include <vector>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
int hammingWeight(uint32_t n) {
  int result = 0;
  uint32_t val = 1;
  for (int i = 0; i < 32; i++) {
    if (val & n) {
      result++;
    }
    val *= 2;
  }
  return result;
}