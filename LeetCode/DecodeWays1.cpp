#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mp;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int numDecodings(string s) {
  if (mp.find(s) != mp.end()) {
    return mp[s];
  }
  if (s[0] == '0') {
    mp[s] = 0;
    return 0;
  }
  int n = s.size();
  if (n == 1) {
    mp[s] = 1;
    return 1;
  }
  mp[s] = numDecodings(s.substr(1));
  if (n > 2 && ((s[0] == '1') || (s[0] == '2' && s[1] - '0' < 7))) {
    mp[s] += numDecodings(s.substr(2));
  }
  if (n == 2 && ((s[0] == '1') || (s[0] == '2' && s[1] - '0' < 7))) {
    mp[s]++;
  }
  return mp[s];
}