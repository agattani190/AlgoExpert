#include <vector>
using namespace std;

bool isBadVersion(int version);

// Time Complexity: O(logn)
// Space Complexity: O(1)
int firstBadVersion(int n) {
  int leftPtr = 0;
  int rightPtr = n;
  int result;
  while (leftPtr <= rightPtr) {
    int mid = leftPtr + ((rightPtr - leftPtr) >> 1);
    if (isBadVersion(mid)) {
      result = mid;
      rightPtr = mid - 1;
    } else {
      leftPtr = mid + 1;
    }
  }
  return result;
}