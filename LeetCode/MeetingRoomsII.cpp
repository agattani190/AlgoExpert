#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int minMeetingRooms(vector<vector<int>> &intervals) {
  int n = intervals.size();
  sort(intervals.begin(), intervals.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int result = 1;
  pq.push(intervals[0][1]);
  for (int i = 1; i < n; i++) {
    if (pq.top() <= intervals[i][0]) {
      pq.pop();
    } else {
      result++;
    }
    pq.push(intervals[i][1]);
  }
  return result;
}