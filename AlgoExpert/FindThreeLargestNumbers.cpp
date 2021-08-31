#include <climits>
#include <vector>
using namespace std;

int getMaxNumberIndex(vector<int> array) {
  int maxNumIndex = 0;
  int maxNum = INT_MIN;
  for (int i = 0; i < array.size(); i++) {
    if (array[i] > maxNum) {
      maxNum = array[i];
      maxNumIndex = i;
    }
  }
  return maxNumIndex;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> findThreeLargestNumbers(vector<int> array) {
  int firstMaxIndex = getMaxNumberIndex(array);
  int firstMax = array[firstMaxIndex];
  array[firstMaxIndex] = INT_MIN;
  int secondMaxIndex = getMaxNumberIndex(array);
  int secondMax = array[secondMaxIndex];
  array[secondMaxIndex] = INT_MIN;
  int thirdMax = array[getMaxNumberIndex(array)];
  array[firstMaxIndex] = firstMax;
  array[secondMaxIndex] = secondMax;
  return {thirdMax, secondMax, firstMax};
}
