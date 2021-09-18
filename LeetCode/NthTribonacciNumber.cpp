#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int tribonacci(int n) {
  if (n < 2) {
    return n;
  }
  if (n == 2) {
    return 1;
  }
  int a = 0;
  int b = 1;
  int c = 1;
  int d;
  for (int i = 3; i <= n; i++) {
    d = a + b + c;
    a = b;
    b = c;
    c = d;
  }
  return d;
}