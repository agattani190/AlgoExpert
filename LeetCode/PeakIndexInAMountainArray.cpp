#include <vector>
using namespace std;

// Time Complexity: O(logn)
// Space Complexity: O(1)
int peakIndexInMountainArray(vector<int> &arr) {
  int n = arr.size();
  int left = 1;
  int right = n - 2;
  int mid;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      break;
    } else if (arr[mid] < arr[mid - 1]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return mid;
}