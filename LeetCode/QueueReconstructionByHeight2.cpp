#include <vector>
using namespace std;

static bool compare(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] > b[0];
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
  int n = people.size();
  vector<vector<int>> result;
  sort(people.begin(), people.end(), compare);
  for (int i = 0; i < n; i++) {
    result.insert(result.begin() + people[i][1], people[i]);
  }
  return result;
}