#include <string>
#include <vector>
using namespace std;

static bool compare(string a, string b) { return a + b > b + a; }

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
string largestNumber(vector<int> &nums) {
  string result;
  int n = nums.size();
  vector<string> num(n);
  for (int i = 0; i < n; i++) {
    num[i] = to_string(nums[i]);
  }

  sort(num.begin(), num.end(), compare);
  if (num[0] == "0") {
    return "0";
  }
  for (int i = 0; i < n; i++) {
    result += num[i];
  }
  return result;
}