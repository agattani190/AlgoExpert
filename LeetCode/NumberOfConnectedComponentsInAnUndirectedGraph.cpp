

#include <vector>
using namespace std;

int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Average Time Complexity: O(m+n)
// Space Complexity: O(n)
int countComponents(int n, vector<vector<int>> &edges) {
  vector<int> tree(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  int m = edges.size();
  for (int i = 0; i < m; i++) {
    unite(edges[i][0], edges[i][1], tree, rank);
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (tree[i] == i) {
      result++;
    }
  }
  return result;
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
  if (x != y) {
    if (rank[x] < rank[y]) {
      tree[x] = y;
    } else if (rank[x] > rank[y]) {
      tree[y] = x;
    } else {
      rank[x]++;
      tree[y] = x;
    }
  }
}