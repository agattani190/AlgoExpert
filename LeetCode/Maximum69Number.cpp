#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int maximum69Number(int num) {
  int reverse = 0;
  while (num) {
    reverse *= 10;
    reverse += (num % 10);
    num /= 10;
  }
  int result = 0;
  bool changed = false;
  while (reverse) {
    result *= 10;
    if (reverse % 10 == 6 && !changed) {
      changed = true;
      result += 9;
    } else {
      result += (reverse % 10);
    }
    reverse /= 10;
  }
  return result;
}