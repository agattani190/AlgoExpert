#include <vector>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph);

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
      dfs(i, visited, graph);
    }
  }
  return result;
}

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph) {
  for (int i = 0; i < graph[u].size(); i++) {
    if (!visited[graph[u][i]]) {
      visited[graph[u][i]] = true;
      dfs(graph[u][i], visited, graph);
    }
  }
}