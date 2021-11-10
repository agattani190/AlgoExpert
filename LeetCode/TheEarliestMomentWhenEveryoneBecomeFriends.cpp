#include <vector>
using namespace std;

int find(int x, vector<int> &tree);
bool unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Time Complexity: O(mlogm)
// Space Complexity: O(n)
int earliestAcq(vector<vector<int>> &logs, int n) {
  int m = logs.size();
  sort(logs.begin(), logs.end());
  int i = 0;
  vector<int> tree(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  while (n > 1 && i < m) {
    if (unite(logs[i][1], logs[i][2], tree, rank)) {
      n--;
    }
    i++;
  }
  if (n == 1) {
    return logs[i - 1][0];
  }
  return -1;
}

int find(int x, vector<int> &tree) {
  if (x == tree[x]) {
    return x;
  }
  tree[x] = find(tree[x], tree);
  return tree[x];
}

bool unite(int u, int v, vector<int> &tree, vector<int> &rank) {
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
    return true;
  }
  return false;
}