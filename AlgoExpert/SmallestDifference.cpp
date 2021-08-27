#include <climits>
#include <math.h>
#include <vector>
using namespace std;

// Time Complexity: O(nlogn + mlogm) -> n,m are sizes of the arrays
// Space Complexity: O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  int ptr1 = 0;
  int ptr2 = 0;
  int arrayOneSize = arrayOne.size();
  int arrayTwoSize = arrayTwo.size();
  int minAbsValue = INT_MAX;
  vector<int> result;
  while (ptr1 < arrayOneSize && ptr2 < arrayTwoSize) {
    if (arrayOne[ptr1] - arrayTwo[ptr2] == 0) {
      return {arrayOne[ptr1], arrayTwo[ptr2]};
    }
    if (abs(arrayOne[ptr1] - arrayTwo[ptr2]) < minAbsValue) {
      minAbsValue = abs(arrayOne[ptr1] - arrayTwo[ptr2]);
      result = {arrayOne[ptr1], arrayTwo[ptr2]};
    }
    if (arrayOne[ptr1] < arrayTwo[ptr2]) {
      ptr1++;
    } else {
      ptr2++;
    }
  }
  return result;
}
