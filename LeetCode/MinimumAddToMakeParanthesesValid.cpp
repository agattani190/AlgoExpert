#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int minAddToMakeValid(string s) {
  int n = s.size();
  int result = 0;
  int openCounter = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      openCounter++;
    } else if (openCounter) {
      openCounter--;
    } else {
      result++;
    }
  }
  result += openCounter;
  return result;
}