#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isConnected(int a, int b, vector<int> &tree);
int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);
void bfs(int u, int v, vector<vector<pair<int, double>>> &graph,
         vector<pair<int, double>> &parent);

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  int n = equations.size();

  unordered_map<string, int> mp;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (mp.find(equations[i][0]) == mp.end()) {
      mp[equations[i][0]] = index++;
    }
    if (mp.find(equations[i][1]) == mp.end()) {
      mp[equations[i][1]] = index++;
    }
  }

  vector<vector<pair<int, double>>> graph(index, vector<pair<int, double>>());
  for (int i = 0; i < n; i++) {
    graph[mp[equations[i][0]]].push_back({mp[equations[i][1]], values[i]});
    graph[mp[equations[i][1]]].push_back(
        {mp[equations[i][0]], 1.0 / values[i]});
  }

  vector<int> tree(index);
  vector<int> rank(index);
  for (int i = 0; i < index; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    unite(mp[equations[i][0]], mp[equations[i][1]], tree, rank);
  }

  int m = queries.size();
  vector<double> result(m);
  int u, v;
  for (int i = 0; i < m; i++) {
    if (mp.find(queries[i][0]) == mp.end() ||
        mp.find(queries[i][1]) == mp.end()) {
      result[i] = -1.0;
    } else if (isConnected(mp[queries[i][0]], mp[queries[i][1]], tree)) {
      vector<pair<int, double>> parent(index, {-1, -1});
      u = mp[queries[i][0]];
      v = mp[queries[i][1]];
      bfs(u, v, graph, parent);
      double val = 1.0;
      while (parent[v].first != -1) {
        val *= parent[v].second;
        v = parent[v].first;
      }
      result[i] = val;
    } else {
      result[i] = -1.0;
    }
  }
  return result;
}

bool isConnected(int a, int b, vector<int> &tree) {
  return find(a, tree) == find(b, tree);
}

int find(int x, vector<int> &tree) {
  if (x == tree[x]) {
    return x;
  }
  tree[x] = find(tree[x], tree);
  return tree[x];
}

void unite(int u, int v, vector<int> &tree, vector<int> &rank) {
  int x = find(u, tree);
  int y = find(v, tree);
  if (rank[x] < rank[y]) {
    tree[x] = y;
  } else if (rank[x] > rank[y]) {
    tree[y] = x;
  } else {
    rank[x]++;
    tree[y] = x;
  }
}

void bfs(int u, int v, vector<vector<pair<int, double>>> &graph,
         vector<pair<int, double>> &parent) {
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
      if (!visited[graph[i][j].first]) {
        parent[graph[i][j].first] = {i, graph[i][j].second};
        if (graph[i][j].first == v) {
          return;
        }
        visited[graph[i][j].first] = true;
        q.push(graph[i][j].first);
      }
    }
  }
}