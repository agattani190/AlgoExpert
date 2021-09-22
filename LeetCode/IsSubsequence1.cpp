#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isSubsequence(string s, string t) {
  int m = s.size();
  int n = t.size();
  if (m > n) {
    return false;
  }
  int j = 0;
  int i = 0;
  while (i < m && j < n) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return i == m;
}