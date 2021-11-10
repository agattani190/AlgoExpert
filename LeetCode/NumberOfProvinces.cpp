#include <vector>
using namespace std;

int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Average Time Complexity: O(n^2)
// Space Complexity: O(n)
int findCircleNum(vector<vector<int>> &isConnected) {
  int n = isConnected.size();
  vector<int> tree(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    tree[i] = i;
    rank[i] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isConnected[i][j]) {
        unite(i, j, tree, rank);
      }
    }
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