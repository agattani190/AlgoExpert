#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
string reverseStr(string s, int k) {
  if (k < 2) {
    return s;
  }
  int n = s.size();
  int start = 0;
  int end = min(k - 1, n - 1);
  int numOfChar = end - start + 1;
  while (numOfChar > 1) {
    for (int i = 0; i < numOfChar / 2; i++) {
      swap(s[start + i], s[end - i]);
    }
    start = min(n - 1, start + 2 * k);
    end = min(n - 1, end + 2 * k);
    numOfChar = end - start + 1;
  }
  return s;
}