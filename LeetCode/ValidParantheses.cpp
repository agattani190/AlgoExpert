#include <stack>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
bool isValid(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        return false;
      }
      char top = st.top();
      if ((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') ||
          (s[i] == ']' && top != '[')) {
        return false;
      }
      st.pop();
    }
  }
  return st.empty();
}