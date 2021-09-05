#include <string>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int lengthOfLongestSubstring(string s) {
  int result = 0;
  int index = 0;
  int leftPtr = 0;
  unordered_map<char, int> mp;
  int n = s.size();
  while (index < n) {
    if (mp.find(s[index]) != mp.end() && mp[s[index]] >= leftPtr) {
      result = max(result, index - leftPtr);
      leftPtr = mp[s[index]] + 1;
    }
    mp[s[index]] = index;
    index++;
  }
  result = max(result, index - leftPtr);
  return result;
}