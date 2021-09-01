#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> tokenize(string s) {
  vector<string> result;
  int start = 0;
  int end = s.find(" ");
  while (end != -1) {
    result.push_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find(" ", start);
  }
  result.push_back(s.substr(start, end - start));
  return result;
}

string reverseStr(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    swap(s[i], s[n - i - 1]);
  }
  return s;
}

string reverseWords(string s) {
  string result;
  vector<string> words = tokenize(s);
  for (int i = 0; i < words.size(); i++) {
    result += reverseStr(words[i]);
    if (i != words.size() - 1) {
      result += " ";
    }
  }
  return result;
}