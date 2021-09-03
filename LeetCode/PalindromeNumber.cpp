#include <iostream>
using namespace std;

int reverse(int x) {
  int result = 0;
  int rem;
  while (x != 0) {
    rem = x % 10;
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && rem > 7))
      return 0;
    if (result < INT_MIN / 10 || (result == INT_MIN / 10 && rem < -8))
      return 0;
    result = result * 10 + rem;
    x /= 10;
  }
  return result;
}

// Time Complexity: O(logx)
// Space Complexity: O(1)
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  } else {
    return x == reverse(x);
  }
}