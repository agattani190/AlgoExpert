#include <vector>
using namespace std;

// Time Complexity: O(wh) -> w, h are width and height of the grid
// Space Complexity: O(wh)
vector<vector<int>> getNeighbours(vector<vector<char>> &grid, int row,
                                  int col) {
  vector<vector<int>> neighbours;
  if (col > 0 && grid[row][col - 1] == '1') {
    grid[row][col - 1] = '0';
    neighbours.push_back({row, col - 1});
  }
  if (col < grid[row].size() - 1 && grid[row][col + 1] == '1') {
    grid[row][col + 1] = '0';
    neighbours.push_back({row, col + 1});
  }
  if (row > 0 && grid[row - 1][col] == '1') {
    grid[row - 1][col] = '0';
    neighbours.push_back({row - 1, col});
  }
  if (row < grid.size() - 1 && grid[row + 1][col] == '1') {
    grid[row + 1][col] = '0';
    neighbours.push_back({row + 1, col});
  }
  return neighbours;
}

void traverseNode(vector<vector<char>> &grid, int row, int col) {
  vector<vector<int>> neighbours = getNeighbours(grid, row, col);
  for (int i = 0; i < neighbours.size(); i++) {
    traverseNode(grid, neighbours[i][0], neighbours[i][1]);
  }
}

int numIslands(vector<vector<char>> &grid) {
  int numOfIslands = 0;
  int rows = grid.size();
  int columns = grid[0].size();
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < columns; col++) {
      if (grid[row][col] == '1') {
        grid[row][col] = '0';
        numOfIslands++;
        traverseNode(grid, row, col);
      }
    }
  }
  return numOfIslands;
}