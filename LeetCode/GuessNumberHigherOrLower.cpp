#include <iostream>
using namespace std;

int guess(int num);

// Time Complexity: O(logn)
// Space Complexity: O(1)
int guessNumber(int n) {
  int low = 1;
  int high = n;
  int mid;
  int guessValue;
  while (low <= high) {
    mid = low + (high - low) / 2;
    guessValue = guess(mid);
    if (guessValue == 0) {
      break;
    } else if (guessValue == 1) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return mid;
}
