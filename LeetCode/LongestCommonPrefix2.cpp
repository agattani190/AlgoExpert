#include <string>
#include <vector>
using namespace std;

string getPrefix(string a, string b);

// Time Complexity: O(s) - s is the number of characteres in all strings
// Space Complexity: O(mlogn) - m is the max number of characteres in a string
string longestCommonPrefix(vector<string> &strs) {
  int n = strs.size();
  if (n == 1) {
    return strs[0];
  }
  int mid = n / 2;
  vector<string> array1(strs.begin(), strs.begin() + mid);
  vector<string> array2(strs.begin() + mid, strs.end());
  string s1 = longestCommonPrefix(array1);
  string s2 = longestCommonPrefix(array2);
  return getPrefix(s1, s2);
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