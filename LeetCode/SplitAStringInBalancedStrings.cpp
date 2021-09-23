#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int balancedStringSplit(string s) {
  int n = s.size();
  int count = s[0] == 'L' ? 1 : -1;
  int i = 1;
  int result = 0;
  while (i < n) {
    if (s[i] == 'L') {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      result++;
    }
    i++;
  }
  return result;
}