#include <queue>
#include <vector>
using namespace std;

void bfs(int u, vector<bool> &visited, vector<vector<int>> &isConnected);

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
      bfs(i, visited, isConnected);
    }
  }
  return result;
}

void bfs(int u, vector<bool> &visited, vector<vector<int>> &isConnected) {
  int n = visited.size();
  queue<int> q;
  q.push(u);
  int i;
  while (!q.empty()) {
    i = q.front();
    q.pop();
    for (int j = 0; j < n; j++) {
      if (isConnected[i][j] && !visited[j]) {
        visited[j] = true;
        q.push(j);
      }
    }
  }
}