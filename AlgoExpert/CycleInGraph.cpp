#include <vector>
using namespace std;

// Time Complexity: O(V + E) -> E is number of edges and V is number of vertices
// Space Complexity: O(V + E)
bool cycleInGraphHelper(vector<vector<int>> edges, vector<bool> &visited,
                        vector<bool> &isInCurrentPath, int node) {
  visited[node] = true;
  isInCurrentPath[node] = true;
  for (int edge = 0; edge < edges[node].size(); edge++) {
    if (!visited[edges[node][edge]]) {
      if (cycleInGraphHelper(edges, visited, isInCurrentPath,
                             edges[node][edge])) {
        return true;
      }
    } else if (isInCurrentPath[edges[node][edge]]) {
      return true;
    }
  }
  isInCurrentPath[node] = false;
  return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  vector<bool> visited(edges.size(), false);
  vector<bool> isInCurrentPath(edges.size(), false);
  for (int node = 0; node < edges.size(); node++) {
    if (!visited[node]) {
      if (cycleInGraphHelper(edges, visited, isInCurrentPath, node)) {
        return true;
      }
    }
  }
  return false;
}