#include <unordered_set>
#include <vector>
using namespace std;

// Average Time Complexity: O(n)
// Space Complexity: O(n)
bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> s;
  for (int i = 0; i < nums.size(); i++) {
    if (s.find(nums[i]) != s.end()) {
      return true;
    }
    s.insert(nums[i]);
  }
  return false;
}