#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hashTable;
  for (int i = 0; i < nums.size(); i++) {
    int otherNum = target - nums[i];
    if (hashTable.find(otherNum) != hashTable.end()) {
      return {hashTable[otherNum], i};
    }
    hashTable[nums[i]] = i;
  }
  return {};
}