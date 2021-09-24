#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int numDecodings(string s) {
  if (s[0] == '0') {
    return 0;
  }
  int n = s.size();
  if (n == 1) {
    return 1;
  }
  int a = 1;
  int b = 1;
  int c;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      if (s[i - 1] - '0' < 1 || s[i - 1] - '0' > 2) {
        return 0;
      }
      c = a;
    } else {
      c = b;
      if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] - '0' < 7)) {
        c += a;
      }
    }
    a = b;
    b = c;
  }
  return c;
}