#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxPower(string s) {
  int n = s.size();
  int res = 1;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      res = max(res, count);
      count = 1;
    }
  }
  res = max(res, count);
  return res;
}