#include <vector>
using namespace std;

// Time Complexity: O(mn) -> m and n are the number of rows and columns
// Space Complexity: O(mn)
void dfs(vector<vector<int>> &image, int sr, int sc, int color, int newColor) {
  if (image[sr][sc] == color) {
    image[sr][sc] = newColor;
    if (sr > 0) {
      dfs(image, sr - 1, sc, color, newColor);
    }
    if (sc > 0) {
      dfs(image, sr, sc - 1, color, newColor);
    }
    if (sr < image.size() - 1) {
      dfs(image, sr + 1, sc, color, newColor);
    }
    if (sc < image[0].size() - 1) {
      dfs(image, sr, sc + 1, color, newColor);
    }
  }
  return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int newColor) {
  int rows = image.size();
  int columns = image[0].size();
  int color = image[sr][sc];
  if (color == newColor) {
    return image;
  }
  dfs(image, sr, sc, color, newColor);
  return image;
}