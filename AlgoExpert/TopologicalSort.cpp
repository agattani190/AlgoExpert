#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  int n = jobs.size();
  int m = deps.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[jobs[i]] = i;
  }
  vector<int> ordering(n, -1);
  vector<int> inDegree(n, 0);
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    graph[mp[deps[i][0]]].push_back(mp[deps[i][1]]);
    inDegree[mp[deps[i][1]]]++;
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      ordering[index++] = jobs[i];
    }
  }
  if (index == n) {
    return ordering;
  }
  for (int i = 0; i < n; i++) {
    if (i >= index || mp.find(ordering[i]) == mp.end()) {
      return {};
    }
    for (int j = 0; j < graph[mp[ordering[i]]].size(); j++) {
      inDegree[graph[mp[ordering[i]]][j]]--;
      if (inDegree[graph[mp[ordering[i]]][j]] == 0) {
        ordering[index++] = jobs[graph[mp[ordering[i]]][j]];
      }
    }
  }
  return ordering;
}
