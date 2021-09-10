#include <vector>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
uint32_t reverseBits(uint32_t n) {
  uint32_t result = 0;
  uint32_t temp = 1 << 31;
  uint32_t val = 1;
  for (int i = 0; i < 32; i++) {
    if (val & n) {
      result += temp;
    }
    temp /= 2;
    val *= 2;
  }
  return result;
}