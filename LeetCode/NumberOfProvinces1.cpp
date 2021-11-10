#include <vector>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &isConnected);

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int findCircleNum(vector<vector<int>> &isConnected) {
  int n = isConnected.size();
  vector<bool> visited(n, false);
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      result++;
      dfs(i, visited, isConnected);
    }
  }
  return result;
}

void dfs(int u, vector<bool> &visited, vector<vector<int>> &isConnected) {
  int n = visited.size();
  for (int i = 0; i < n; i++) {
    if (isConnected[u][i] && !visited[i]) {
      visited[i] = true;
      dfs(i, visited, isConnected);
    }
  }
}