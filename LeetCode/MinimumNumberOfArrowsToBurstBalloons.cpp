#include <vector>
using namespace std;

// Sort based on the second value
static bool compare(vector<int> &A, vector<int> &B) { return A[1] < B[1]; }

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int findMinArrowShots(vector<vector<int>> &points) {
  int n = points.size();
  sort(points.begin(), points.end(), compare);
  int minArrows = 1;
  int currentFurthestindex = points[0][1];
  for (int i = 1; i < n; i++) {
    if (points[i][0] > currentFurthestindex) {
      minArrows++;
      currentFurthestindex = points[i][1];
    }
  }
  return minArrows;
}