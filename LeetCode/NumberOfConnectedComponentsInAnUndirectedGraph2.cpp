#include <queue>
#include <vector>
using namespace std;

void bfs(int u, vector<bool> &visited, vector<vector<int>> &graph);

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
int countComponents(int n, vector<vector<int>> &edges) {
  vector<vector<int>> graph(n, vector<int>());
  int m = edges.size();
  for (int i = 0; i < m; i++) {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }
  vector<bool> visited(n, false);
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      result++;
      bfs(i, visited, graph);
    }
  }
  return result;
}

void bfs(int u, vector<bool> &visited, vector<vector<int>> &graph) {
  int n = visited.size();
  queue<int> q;
  q.push(u);
  int i;
  while (!q.empty()) {
    i = q.front();
    q.pop();
    for (int j = 0; j < graph[i].size(); j++) {
      if (!visited[graph[i][j]]) {
        visited[graph[i][j]] = true;
        q.push(graph[i][j]);
      }
    }
  }
}