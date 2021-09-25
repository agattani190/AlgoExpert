#include <set>
#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
bool isOverlapping(pair<int, int> a, pair<int, int> b);
int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  int n = intervals.size();
  if (n == 1) {
    return 0;
  }
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    s.insert({intervals[i][0], intervals[i][1]});
  }
  vector<pair<int, int>> uniqueIntervals;
  for (auto interval : s) {
    uniqueIntervals.push_back(interval);
  }
  int newSize = uniqueIntervals.size();
  int result = n - newSize;
  pair<int, int> currInterval = uniqueIntervals[0];
  for (int i = 1; i < newSize; i++) {
    if (isOverlapping(currInterval, uniqueIntervals[i])) {
      result++;
      if (currInterval.second > uniqueIntervals[i].second) {
        currInterval = uniqueIntervals[i];
      }
    } else {
      currInterval = uniqueIntervals[i];
    }
  }
  return result;
}

bool isOverlapping(pair<int, int> a, pair<int, int> b) {
  if (a.second <= b.first) {
    return false;
  }
  return true;
}
