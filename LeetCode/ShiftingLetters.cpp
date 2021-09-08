#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
string shiftingLetters(string s, vector<int> &shifts) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    shifts[i] %= 26;
  }
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    count += shifts[i];
    count %= 26;
    if (s[i] + count > 'z') {
      s[i] += (count - 26);
    } else {
      s[i] += count;
    }
  }
  return s;
}