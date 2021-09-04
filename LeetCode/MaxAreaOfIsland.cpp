#include <vector>
using namespace std;

// Time Complexity: O(mn) -> m and n are the number of rows and columns
// Space Complexity: O(mn)
vector<vector<int>> getNeighbours(vector<vector<int>> &grid, int row, int col) {
  vector<vector<int>> neighbours;
  if (col > 0 && grid[row][col - 1] == 1) {
    grid[row][col - 1] = -1;
    neighbours.push_back({row, col - 1});
  }
  if (col < grid[row].size() - 1 && grid[row][col + 1] == 1) {
    grid[row][col + 1] = -1;
    neighbours.push_back({row, col + 1});
  }
  if (row > 0 && grid[row - 1][col] == 1) {
    grid[row - 1][col] = -1;
    neighbours.push_back({row - 1, col});
  }
  if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
    grid[row + 1][col] = -1;
    neighbours.push_back({row + 1, col});
  }
  return neighbours;
}

int traverseNode(vector<vector<int>> &grid, int row, int col, int currentSize) {
  vector<vector<int>> neighbours = getNeighbours(grid, row, col);
  for (int i = 0; i < neighbours.size(); i++) {
    currentSize++;
    currentSize =
        traverseNode(grid, neighbours[i][0], neighbours[i][1], currentSize);
  }
  return currentSize;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
  int maxArea = 0;
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      if (grid[row][col] == 1) {
        grid[row][col] = -1;
        maxArea = max(maxArea, traverseNode(grid, row, col, 1));
      }
    }
  }
  return maxArea;
}