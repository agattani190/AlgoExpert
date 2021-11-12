#include <vector>
using namespace std;

bool isConnected(int a, int b, vector<int> &tree);
int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Time Complexity: O((n+m)log(n+m))
// Space Complexity: O(n+m)
int minCostToSupplyWater(int n, vector<int> &wells,
                         vector<vector<int>> &pipes) {
  int m = pipes.size();
  vector<pair<int, pair<int, int>>> edges(m + n);
  int index = 0;
  for (int i = 0; i < n; i++) {
    edges[index++] = {wells[i], {0, i + 1}};
  }
  for (int i = 0; i < m; i++) {
    edges[index++] = {pipes[i][2], {pipes[i][0], pipes[i][1]}};
  }
  sort(edges.begin(), edges.end());
  vector<int> tree(n + 1);
  vector<int> rank(n + 1);
  for (int i = 0; i < n + 1; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  int result = 0;
  int count = 0;
  index = 0;

  while (count < n) {
    if (!isConnected(edges[index].second.first, edges[index].second.second,
                     tree)) {
      result += edges[index].first;
      count++;
      unite(edges[index].second.first, edges[index].second.second, tree, rank);
    }
    index++;
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