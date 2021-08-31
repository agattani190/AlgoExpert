#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> twoSum(vector<int> &numbers, int target) {
  int leftPtr = 0;
  int rightPtr = numbers.size() - 1;
  while (leftPtr < rightPtr) {
    if (numbers[leftPtr] + numbers[rightPtr] == target) {
      break;
    } else if (numbers[leftPtr] + numbers[rightPtr] < target) {
      leftPtr++;
    } else {
      rightPtr--;
    }
  }
  return {leftPtr + 1, rightPtr + 1};
}
