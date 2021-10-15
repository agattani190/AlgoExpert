#include <string>
#include <vector>
using namespace std;

static bool compare(vector<int> a, vector<int> b) {
  return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  int n = points.size();
  sort(points.begin(), points.end(), compare);
  return vector<vector<int>>(points.begin(), points.begin() + k);
}