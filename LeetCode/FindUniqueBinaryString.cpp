#include <string>
#include <vector>
using namespace std;

int getDecVal(string s);
string getBinStr(int dec, int bits);

// Time Complexity: O(mn)
// Space Complexity: O(n)
string findDifferentBinaryString(vector<string> &nums) {
  int n = nums.size();
  int m = nums[0].size();
  vector<bool> isPresent(n, false);
  int dec;
  for (int i = 0; i < n; i++) {
    dec = getDecVal(nums[i]);
    if (dec < n) {
      isPresent[dec] = true;
    }
  }
  int res = n;
  for (int i = 0; i < n; i++) {
    if (!isPresent[i]) {
      res = i;
      break;
    }
  }
  return getBinStr(res, m);
}

int getDecVal(string s) {
  int n = s.size();
  int dec = 0;
  int mul = 1;
  for (int i = n - 1; i >= 0; i--) {
    dec += (mul * (s[i] - '0'));
    mul *= 2;
  }
  return dec;
}

string getBinStr(int dec, int bits) {
  string bin = "";
  while (dec > 0) {
    bin += ('0' + (dec % 2));
    dec /= 2;
  }
  int diff = bits - bin.size();
  while (diff--) {
    bin += '0';
  }
  for (int i = 0; i < bits / 2; i++) {
    swap(bin[i], bin[bits - i - 1]);
  }
  return bin;
}