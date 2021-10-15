#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
  int n = points.size();
  int result = -1;
  int minDistance = INT_MAX;
  int distance;
  for (int i = 0; i < n; i++) {
    if (points[i][0] == x || points[i][1] == y) {
      distance = abs(points[i][0] - x) + abs(points[i][1] - y);
      if (distance < minDistance) {
        minDistance = distance;
        result = i;
      }
    }
  }
  return result;
}