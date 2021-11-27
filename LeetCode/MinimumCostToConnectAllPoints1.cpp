#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(n^2logn)
// Space Complexity: O(n^2)
int minCostConnectPoints(vector<vector<int>> &points) {
  int n = points.size();
  if (n == 1) {
    return 0;
  }
  vector<bool> visited(n, false);
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  visited[0] = true;
  for (int i = 1; i < n; i++) {
    pq.push(
        {abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]),
         {0, i}});
  }
  int result = 0;
  int k = 1;
  int u, v, c;
  while (k < n) {
    u = pq.top().second.first;
    v = pq.top().second.second;
    c = pq.top().first;
    pq.pop();
    if (!visited[v]) {
      visited[v] = true;
      result += c;
      k++;
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          pq.push({abs(points[v][0] - points[i][0]) +
                       abs(points[v][1] - points[i][1]),
                   {v, i}});
        }
      }
    }
  }
  return result;
}