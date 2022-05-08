#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> mergedIntervals;
  vector<int> currentInterval = intervals[0];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] > currentInterval[1]) {
      mergedIntervals.push_back(currentInterval);
      currentInterval = intervals[i];
    } else {
      currentInterval[1] = max(currentInterval[1], intervals[i][1]);
    }
  }
  mergedIntervals.push_back(currentInterval);
  return mergedIntervals;
}