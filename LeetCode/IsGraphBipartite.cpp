#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v)
bool isBipartite(vector<vector<int>> &graph) {
  queue<int> q;
  int n = graph.size();
  vector<int> level(n, 0);
  vector<bool> visited(n, false);
  int size;
  int count = 0;
  int curr;
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    q.push(i);
    while (!q.empty()) {
      size = q.size();
      while (size--) {
        curr = q.front();
        q.pop();
        if (!visited[curr]) {
          visited[curr] = true;
          level[curr] = count;
          for (int i = 0; i < graph[curr].size(); i++) {
            q.push(graph[curr][i]);
          }
        }
      }
      count++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      if ((level[i] + level[graph[i][j]]) % 2 == 0) {
        return false;
      }
    }
  }
  return true;
}