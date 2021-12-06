#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int minCostToMoveChips(vector<int> &position) {
  int n = position.size();
  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if (position[i] % 2) {
      odd++;
    } else {
      even++;
    }
  }
  return min(even, odd);
}