#include <string>
#include <vector>
using namespace std;

string getPrefix(string a, string b);

// Time Complexity: O(s) - s is the number of characteres in all strings
// Space Complexity: O(1)
string longestCommonPrefix(vector<string> &strs) {
  int n = strs.size();
  string result = strs[0];
  for (int i = 1; i < n; i++) {
    result = getPrefix(result, strs[i]);
  }
  return result;
}

string getPrefix(string a, string b) {
  int m = a.size();
  int n = b.size();
  int i = 0;
  int j = 0;
  string prefix = "";
  while (i < m && j < n) {
    if (a[i] == b[j]) {
      prefix += a[i];
      i++;
      j++;
    } else {
      break;
    }
  }
  return prefix;
}