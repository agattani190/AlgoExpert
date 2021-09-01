#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
string reverseWords(string s) {
  vector<string> words;
  int n = s.size();
  int start = 0;
  while (start < n && s[start] == ' ') {
    start++;
  }
  int end = s.find(" ", start);
  while (end != -1) {
    words.push_back(s.substr(start, end - start));
    start = end + 1;
    while (start < n && s[start] == ' ') {
      start++;
    }
    end = s.find(" ", start);
  }
  if (start < n) {
    words.push_back(s.substr(start, end - start));
  }
  string result;
  for (int i = words.size() - 1; i >= 0; i--) {
    result += words[i];
    if (i != 0) {
      result += " ";
    }
  }
  return result;
}