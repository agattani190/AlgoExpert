#include <vector>
using namespace std;

bool isConnected(int a, int b, vector<int> &tree);
int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Time Complexity: O(n^2logn)
// Space Complexity: O(n^2)
int minCostConnectPoints(vector<vector<int>> &points) {
  int n = points.size();
  if (n == 1) {
    return 0;
  }
  vector<pair<int, pair<int, int>>> edges(n * (n - 1));
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      edges[k++] = {abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]),
                    {i, j}};
    }
  }
  sort(edges.begin(), edges.end());
  vector<int> tree(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  int result = 0;
  k = 1;
  int i = 0;
  int u, v, c;
  while (k < n) {
    u = edges[i].second.first;
    v = edges[i].second.second;
    c = edges[i].first;
    i++;
    if (!isConnected(u, v, tree)) {
      unite(u, v, tree, rank);
      result += c;
      k++;
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