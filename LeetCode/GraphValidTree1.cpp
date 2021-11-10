
#include <vector>
using namespace std;

bool dfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
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
  return !dfs(edges[0][0], visited, graph, parent);
}

bool dfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &parent) {
  for (int i = 0; i < graph[u].size(); i++) {
    if (!visited[graph[u][i]]) {
      visited[graph[u][i]] = true;
      parent[graph[u][i]] = u;
      return dfs(graph[u][i], visited, graph, parent);
    } else if (parent[u] != graph[u][i]) {
      return true;
    }
  }
  return false;
}