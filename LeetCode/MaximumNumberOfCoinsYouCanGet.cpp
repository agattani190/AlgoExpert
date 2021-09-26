#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxCoins(vector<int> &piles) {
  int n = piles.size();
  int result = 0;
  sort(piles.begin(), piles.end());
  for (int i = n - 2; i >= n / 3; i -= 2) {
    result += piles[i];
  }
  return result;
}