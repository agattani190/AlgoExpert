#include <unordered_map>
#include <vector>
using namespace std;

// Average Time Complexity: O(n)
// Space Complexity: O(n)
int findShortestSubArray(vector<int> &nums) {
  int n = nums.size();
  unordered_map<int, pair<int, pair<int, int>>> mp;
  int degree = 1;
  for (int i = 0; i < n; i++) {
    if (mp.find(nums[i]) == mp.end()) {
      mp[nums[i]] = {1, {i, i}};
    } else {
      mp[nums[i]] = {mp[nums[i]].first + 1, {mp[nums[i]].second.first, i}};
      degree = max(degree, mp[nums[i]].first);
    }
  }
  int result = n;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second.first == degree) {
      result =
          min(result, it->second.second.second - it->second.second.first + 1);
    }
  }
  return result;
}