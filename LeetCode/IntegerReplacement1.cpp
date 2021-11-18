#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int integerReplacement(int n) {
  if (n == INT_MAX) {
    n--;
  }
  bool flag = false;
  int result = 0;
  while (n > 1) {
    if (n == 3) {
      flag = true;
      break;
    }
    if (n % 2) {
      if (((n - 1) / 2) % 2) {
        n++;
      } else {
        n--;
      }
    } else {
      n /= 2;
    }
    result++;
  }
  if (flag) {
    return result + 2;
  }
  return result;
  ;
}