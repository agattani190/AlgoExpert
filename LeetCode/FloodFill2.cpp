#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(mn) -> m and n are the number of rows and columns
// Space Complexity: O(mn)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int newColor) {
  int rows = image.size();
  int columns = image[0].size();
  int color = image[sr][sc];
  vector<vector<bool>> visited;
  for (int i = 0; i < rows; i++) {
    visited.push_back(vector<bool>(columns, false));
  }
  stack<pair<int, int>> s;
  s.push(make_pair(sr, sc));
  while (!s.empty()) {
    sr = s.top().first;
    sc = s.top().second;
    s.pop();
    if (!visited[sr][sc]) {
      visited[sr][sc] = true;
      if (image[sr][sc] == color) {
        image[sr][sc] = newColor;
        if (sr > 0) {
          s.push(make_pair(sr - 1, sc));
        }
        if (sc > 0) {
          s.push(make_pair(sr, sc - 1));
        }
        if (sr < rows - 1) {
          s.push(make_pair(sr + 1, sc));
        }
        if (sc < columns - 1) {
          s.push(make_pair(sr, sc + 1));
        }
      }
    }
  }
  return image;
}