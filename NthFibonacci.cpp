#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int getNthFib(int n) {
  if (n < 2) {
    return n;
  }
  int a = 0;
  int b = 1;
  int result;
  for (int i = 2; i < n; i++) {
    result = a + b;
    a = b;
    b = result;
  }
  return result;
}
