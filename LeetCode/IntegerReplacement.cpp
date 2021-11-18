#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(logn)
int integerReplacement(int n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  if (n % 2) {
    return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
  } else {
    return 1 + integerReplacement(n / 2);
  }
}