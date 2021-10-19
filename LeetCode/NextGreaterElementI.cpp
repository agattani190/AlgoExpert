#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  int n = nums2.size();
  int m = nums1.size();
  vector<int> result(m);
  unordered_map<int, int> mp;
  mp[nums2[n - 1]] = -1;
  stack<int> s;
  s.push(nums2[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    while (!s.empty() && s.top() < nums2[i]) {
      s.pop();
    }
    if (s.empty()) {
      mp[nums2[i]] = -1;
    } else {
      mp[nums2[i]] = s.top();
    }
    s.push(nums2[i]);
  }
  for (int i = 0; i < m; i++) {
    result[i] = mp[nums1[i]];
  }
  return result;
}