#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                  vector<int> &profit) {
  int n = startTime.size();
  vector<pair<pair<int, int>, int>> jobs(n);
  for (int i = 0; i < n; i++) {
    jobs[i] = {{startTime[i], endTime[i]}, profit[i]};
  }
  sort(jobs.begin(), jobs.end());
  for (int i = 0; i < n; i++) {
    startTime[i] = jobs[i].first.first;
  }
  int nextValidIndex;
  vector<int> dp(n, 0);
  dp[n - 1] = jobs[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = max(jobs[i].second, dp[i + 1]);
    nextValidIndex = lower_bound(startTime.begin() + i, startTime.end(),
                                 jobs[i].first.second) -
                     startTime.begin();
    if (nextValidIndex < n) {
      dp[i] = max(dp[i], jobs[i].second + dp[nextValidIndex]);
    }
  }
  return dp[0];
}