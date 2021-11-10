#include <queue>
#include <vector>
using namespace std;

bool bfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &parent);

// Time Complexity: O(n)
// Space Complexity: O(n)
bool validTree(int n, vector<vector<int>> &edges) {
  if (n == 1) {
    return true;
  }
  int m = edges.size();
  if (m != n - 1) {
    return false;
  }

  vector<vector<int>> graph(n, vector<int>());
  for (int i = 0; i < m; i++) {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }
  vector<bool> visited(n, false);
  vector<int> parent(n, -1);
  visited[edges[0][0]] = true;
  return !bfs(edges[0][0], visited, graph, parent);
}

bool bfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &parent) {
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
        parent[graph[i][j]] = i;
        q.push(graph[i][j]);
      } else if (parent[i] != graph[i][j]) {
        return true;
      }
    }
  }
  return false;
}