#include <string>
#include <vector>
using namespace std;

int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Average Time Complexity: O(m + n + nlogn)
// Space Complexity: O(n)
string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
  int n = s.size();
  int m = pairs.size();
  vector<int> tree(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    unite(pairs[i][0], pairs[i][1], tree, rank);
  }
  vector<vector<int>> components(n, vector<int>());
  for (int i = 0; i < n; i++) {
    components[find(i, tree)].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    string t = "";
    for (int j = 0; j < components[i].size(); j++) {
      t += s[components[i][j]];
    }
    sort(t.begin(), t.end());
    for (int j = 0; j < components[i].size(); j++) {
      s[components[i][j]] = t[j];
    }
  }
  return s;
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