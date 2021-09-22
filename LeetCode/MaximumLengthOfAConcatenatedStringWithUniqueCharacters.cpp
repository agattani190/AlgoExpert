#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
int numOfUniqueCharacters(string &s) {
  vector<int> frequency(26, 0);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    frequency[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (frequency[i] > 1)
      return -1;
  }
  return n;
}

int concat(vector<string> &arr, string base, int i, int result) {
  if (base.size() > 26) {
    return result;
  }
  if (i == arr.size()) {
    result = max(result, numOfUniqueCharacters(base));
    return result;
  }
  return max(concat(arr, base, i + 1, result),
             concat(arr, base + arr[i], i + 1, result));
}

int maxLength(vector<string> &arr) { return concat(arr, "", 0, 0); }