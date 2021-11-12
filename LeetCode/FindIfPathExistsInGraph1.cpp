#include <queue>
#include <vector>
using namespace std;

bool bfs(int u, int v, vector<vector<int>> &graph);

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  if (start == end) {
    return true;
  }
  vector<vector<int>> graph(n, vector<int>());
  int m = edges.size();
  for (int i = 0; i < m; i++) {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }
  vector<bool> visited(n, false);
  visited[start] = true;
  return bfs(start, end, graph);
}

bool bfs(int u, int v, vector<vector<int>> &graph) {
  int n = graph.size();
  vector<bool> visited(n, false);
  visited[u] = true;
  queue<int> q;
  q.push(u);
  int i;
  while (!q.empty()) {
    i = q.front();
    q.pop();
    for (int j = 0; j < graph[i].size(); j++) {
      if (graph[i][j] == v) {
        return true;
      }
      if (!visited[graph[i][j]]) {
        visited[graph[i][j]] = true;
        q.push(graph[i][j]);
      }
    }
  }
  return false;
}