#include <unordered_map>
#include <vector>
using namespace std;

// Average Time Complexity: O(n)
// Space Complexity: O(n)
bool containsNearbyDuplicate(vector<int> &nums, int k) {
  unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) {
    if (mp.find(nums[i]) == mp.end() || i - mp[nums[i]] > k) {
      mp[nums[i]] = i;
    } else {
      return true;
    }
  }
  return false;
}