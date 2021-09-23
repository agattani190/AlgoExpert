#include <vector>
using namespace std;

// Time Complexity: O(min(m,n))
// Space Complexity: O(1)
int uniquePaths(int m, int n) {
  int a = m + n - 2;
  int b = min(m, n) - 1;
  int result = 1;
  for (int i = 1; i <= b; i++) {
    result /= i;
    result *= (a - i + 1);
  }
  return result;
}