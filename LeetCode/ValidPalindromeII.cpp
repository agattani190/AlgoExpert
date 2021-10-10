#include <string>
using namespace std;

bool checkPalindrome(int low, int high, string s);

// Time Complexity: O(n)
// Space Complexity: O(1)
bool validPalindrome(string s) {
  int n = s.size();
  int low = 0;
  int high = n - 1;
  while (s[low] == s[high] && low < high) {
    low++;
    high--;
  }
  return checkPalindrome(low + 1, high, s) || checkPalindrome(low, high - 1, s);
}

bool checkPalindrome(int low, int high, string s) {
  while (low < high) {
    if (s[low] == s[high]) {
      low++;
      high--;
    } else {
      return false;
    }
  }
  return true;
}