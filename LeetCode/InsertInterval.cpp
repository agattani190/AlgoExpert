#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> mergedIntervals;
  auto position = lower_bound(intervals.begin(), intervals.end(), newInterval);
  intervals.insert(position, newInterval);
  int n = intervals.size();
  vector<int> intervalToInsert = intervals[0];
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] > intervalToInsert[1]) {
      mergedIntervals.push_back(intervalToInsert);
      intervalToInsert = intervals[i];
    } else {
      intervalToInsert[1] = max(intervalToInsert[1], intervals[i][1]);
    }
  }
  mergedIntervals.push_back(intervalToInsert);
  return mergedIntervals;
}