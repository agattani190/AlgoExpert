#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void rotate(vector<int> &nums, int k) {
  int numsSize = nums.size();
  k %= numsSize;
  if (k == 0) {
    return;
  }
  int numOfSets = gcd(numsSize, k);
  int counter;
  int currVal;
  int index;
  for (int i = 0; i < numOfSets; i++) {
    counter = 0;
    currVal = nums[i];
    index = i;
    while (counter < numsSize / numOfSets) {
      counter++;
      index = (index + k) % numsSize;
      swap(currVal, nums[index]);
    }
  }
}