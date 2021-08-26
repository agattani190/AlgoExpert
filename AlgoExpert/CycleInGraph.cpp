#include <vector>
using namespace std;

// Time Complexity: O(V + E) -> E is number of edges and V is number of vertices
// Space Complexity: O(V + E)
bool cycleInGraphHelper(vector<vector<int>> edges, vector<bool> &visited,
                        int node) {
  if (visited[node]) {
    return true;
  }
  visited[node] = true;
  for (int edge = 0; edge < edges[node].size(); edge++) {
    if (cycleInGraphHelper(edges, visited, edges[node][edge])) {
      return true;
    }
  }
  visited[node] = false;
  return false;
}
bool cycleInGraph(vector<vector<int>> edges) {
  vector<bool> visited(edges.size());
  for (int node = 0; node < edges.size(); node++) {
    if (!visited[node]) {
      if (cycleInGraphHelper(edges, visited, node)) {
        return true;
      }
    }
  }
  return false;
}