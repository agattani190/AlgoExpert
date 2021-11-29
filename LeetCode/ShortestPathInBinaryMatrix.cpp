#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
  int n = grid.size();
  if (grid[0][0] || grid[n - 1][n - 1]) {
    return -1;
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  grid[0][0] = 1;
  int level = 1;
  int sz;
  int u, v;
  while (!q.empty()) {
    sz = q.size();
    while (sz--) {
      u = q.front().first;
      v = q.front().second;
      q.pop();
      if (u == n - 1 && v == n - 1) {
        return level;
      }
      if (u - 1 >= 0 && v - 1 >= 0 && grid[u - 1][v - 1] == 0) {
        grid[u - 1][v - 1] = 1;
        q.push({u - 1, v - 1});
      }
      if (u - 1 >= 0 && grid[u - 1][v] == 0) {
        grid[u - 1][v] = 1;
        q.push({u - 1, v});
      }
      if (u - 1 >= 0 && v + 1 < n && grid[u - 1][v + 1] == 0) {
        grid[u - 1][v + 1] = 1;
        q.push({u - 1, v + 1});
      }
      if (v - 1 >= 0 && grid[u][v - 1] == 0) {
        grid[u][v - 1] = 1;
        q.push({u, v - 1});
      }
      if (v + 1 < n && grid[u][v + 1] == 0) {
        grid[u][v + 1] = 1;
        q.push({u, v + 1});
      }
      if (u + 1 < n && v - 1 >= 0 && grid[u + 1][v - 1] == 0) {
        grid[u + 1][v - 1] = 1;
        q.push({u + 1, v - 1});
      }
      if (u + 1 < n && grid[u + 1][v] == 0) {
        grid[u + 1][v] = 1;
        q.push({u + 1, v});
      }
      if (u + 1 < n && v + 1 < n && grid[u + 1][v + 1] == 0) {
        grid[u + 1][v + 1] = 1;
        q.push({u + 1, v + 1});
      }
    }
    level++;
  }
  return -1;
}