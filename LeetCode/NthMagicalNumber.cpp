#include <vector>
using namespace std;

int getGCD(int a, int b);
long getLCM(int a, int b);

// Time Complexity: O(log(n*min(a,b))
// Space Complexity: O(1)
int nthMagicalNumber(int n, int a, int b) {
  long lcm = getLCM(a, b);
  long low = min(a, b);
  long high = n * low;
  long mid;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (mid / a + mid / b - mid / lcm < n) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (int)(low % (1000000007));
}

int getGCD(int a, int b) {
  if (b == 0) {
    return a;
  }
  return getGCD(b, a % b);
}

long getLCM(int a, int b) { return (long)a / getGCD(a, b) * b; }