#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int maxNumberOfApples(vector<int> &weight) {
  int n = weight.size();
  sort(weight.begin(), weight.end());

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += weight[i];
    if (sum > 5000) {
      return i;
    }
  }
  return n;
}