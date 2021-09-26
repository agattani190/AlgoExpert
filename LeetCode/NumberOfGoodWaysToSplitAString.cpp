#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int numSplits(string s) {
  int n = s.size();
  vector<int> frequency1(26, 0);
  vector<int> frequency2(26, 0);
  int unique1 = 0;
  int unique2 = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    frequency1[s[i] - 'a']++;
    if (frequency1[s[i] - 'a'] == 1) {
      unique1++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    frequency2[s[i] - 'a']++;
    if (frequency2[s[i] - 'a'] == 1) {
      unique2++;
    }
    frequency1[s[i] - 'a']--;
    if (frequency1[s[i] - 'a'] == 0) {
      unique1--;
    }
    if (unique1 == unique2) {
      result++;
    }
  }
  return result;
}