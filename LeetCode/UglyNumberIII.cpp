#include <vector>
using namespace std;

long long gcd(long long a, long long b);

long long lcm(long long a, long long b);

int getNumbers(int n, int a, int b, int c, long long ab, long long ac,
               long long bc, long long abc);

// Time Complexity: O(log(INT_MAX))
// Space Complexity: O(log(max(a,b,c))
int nthUglyNumber(int n, int a, int b, int c) {
  int left = 1;
  int right = INT_MAX;
  int mid, temp;
  long long ab = lcm(a, b);
  long long ac = lcm(a, c);
  long long bc = lcm(b, c);
  long long abc = lcm(ab, c);
  while (left <= right) {
    mid = left + (right - left) / 2;
    temp = getNumbers(mid, a, b, c, ab, ac, bc, abc);
    if (temp < n) {
      left = mid + 1;
    } else if (temp > n) {
      right = mid - 1;
    } else {
      if (mid % a == 0 || mid % b == 0 || mid % c == 0) {
        break;
      }
      right = mid - 1;
    }
  }
  return mid;
}

long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

int getNumbers(int n, int a, int b, int c, long long ab, long long ac,
               long long bc, long long abc) {
  return n / a - n / ab - n / bc - n / ac + n / abc + n / b + n / c;
}