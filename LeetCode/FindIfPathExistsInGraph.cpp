#include <vector>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph);

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
  dfs(start, visited, graph);
  return visited[end];
}

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph) {
  for (int i = 0; i < graph[u].size(); i++) {
    if (!visited[graph[u][i]]) {
      visited[graph[u][i]] = true;
      dfs(graph[u][i], visited, graph);
    }
  }
}