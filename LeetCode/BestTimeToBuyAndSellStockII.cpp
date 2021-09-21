#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfit(vector<int> &prices) {
  int profit = 0;
  int prev = prices[0];
  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prev) {
      profit += (prices[i] - prev);
    }
    prev = prices[i];
  }
  return profit;
}