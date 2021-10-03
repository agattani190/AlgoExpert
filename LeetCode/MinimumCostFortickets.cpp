#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int mincostTickets(vector<int> &days, vector<int> &costs) {
  int n = days.size();
  vector<int> dp(n + 1, 0);
  dp[1] = min(min(costs[0], costs[1]), costs[2]);
  int lower1, lower2;
  for (int i = 2; i <= n; i++) {
    lower1 = lower_bound(days.begin(), days.begin() + i - 1, days[i - 1] - 7) -
             days.begin();
    lower2 = lower_bound(days.begin(), days.begin() + i - 1, days[i - 1] - 30) -
             days.begin();
    dp[i] = dp[i - 1] + dp[1];
    if (lower1 != i - 1) {
      if (days[lower1] > days[i - 1] - 7) {
        lower1--;
      }
      dp[i] = min(dp[i], dp[lower1 + 1] + costs[1]);
    }
    if (lower2 != i - 1) {
      if (days[lower2] > days[i - 1] - 30) {
        lower2--;
      }
      dp[i] = min(dp[i], dp[lower2 + 1] + costs[2]);
    }
  }
  return dp[n];
}