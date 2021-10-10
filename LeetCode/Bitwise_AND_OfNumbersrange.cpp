#include <iostream>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
int rangeBitwiseAnd(int left, int right) {
  while (left < right) {
    right = right & (right - 1);
  }
  return left & right;
}