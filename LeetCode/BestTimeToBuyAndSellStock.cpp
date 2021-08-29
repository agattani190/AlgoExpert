#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfit(vector<int> &prices) {
  int profit = 0;
  int currMin = INT_MAX;
  for (int i = 0; i < prices.size(); i++) {
    profit = max(profit, prices[i] - currMin);
    currMin = min(currMin, prices[i]);
  }
  return profit;
}