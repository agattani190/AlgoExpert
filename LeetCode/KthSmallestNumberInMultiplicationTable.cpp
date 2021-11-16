#include <iostream>
using namespace std;

int isEnough(int m, int n, int k, int val);

// Time Complexity: O(min(m,n)log(mn))
// Space Complexity: O(1)
int findKthNumber(int m, int n, int k) {
  int low = 1;
  int high = m * n;
  int mid, res;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (isEnough(m, n, k, mid)) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return res;
}

int isEnough(int m, int n, int k, int val) {
  int count = 0;
  if (m > n) {
    swap(m, n);
  }
  for (int i = 1; i <= m; i++) {
    count += min(val / i, n);
  }
  return count >= k;
}