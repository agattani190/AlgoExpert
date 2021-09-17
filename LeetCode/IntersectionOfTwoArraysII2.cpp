#include <unordered_map>
#include <vector>
using namespace std;

// Average Time Complexity: O(n1log(n1) + n2log(n2))
// Space Complexity: O(n1)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> mp;
  vector<int> result;
  for (auto i : nums1) {
    mp[i]++;
  }
  for (auto i : nums2) {
    if (mp[i]) {
      result.push_back(i);
      mp[i]--;
    }
  }
  return result;
}