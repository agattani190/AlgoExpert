#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
int even = 0;
int odd = 0;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src) {
  visited[src] = true;
  for (unsigned int i = 0; i < graph[src].size(); i++) {
    if (!visited[graph[src][i]]) {
      dfs(graph, visited, graph[src][i]);
    }
  }
  s.push(src);
}

int DFS(vector<vector<int>> &graph, vector<bool> &visited, int src, int count) {
  visited[src] = true;
  for (unsigned int i = 0; i < graph[src].size(); i++) {
    if (visited[graph[src][i]] == false) {
      count = DFS(graph, visited, graph[src][i], count + 1);
    }
  }
  return count;
}

// Time Complexity: O(n + e)
// Space Complexity: O(n + e)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, e;
  cin >> n >> e;
  vector<vector<int>> graph(n, vector<int>{});
  vector<vector<int>> transposeGraph(n, vector<int>{});
  int u, v;
  for (int i = 0; i < e; i++) {
    cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    transposeGraph[v - 1].push_back(u - 1);
  }

  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      dfs(graph, visited, i);
    }
  }

  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    int c;
    if (!visited[top]) {
      c = DFS(transposeGraph, visited, top, 0);
    }
    if (c % 2) {
      odd++;
    } else {
      even++;
    }
  }

  cout << even - odd;
  return 0;
}
