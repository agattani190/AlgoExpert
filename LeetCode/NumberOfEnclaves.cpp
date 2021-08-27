#include <vector>
using namespace std;

// Time Complexity: O(wh) -> w, h are width and height of the grid
// Space Complexity: O(wh)
vector<vector<int>> getNeighbours(vector<vector<int>> &grid, int row, int col) {
  vector<vector<int>> neighbours;
  if (col > 0 && grid[row][col - 1] == 1) {
    grid[row][col - 1] = 0;
    neighbours.push_back({row, col - 1});
  }
  if (col < grid[row].size() - 1 && grid[row][col + 1] == 1) {
    grid[row][col + 1] = 0;
    neighbours.push_back({row, col + 1});
  }
  if (row > 0 && grid[row - 1][col] == 1) {
    grid[row - 1][col] = 0;
    neighbours.push_back({row - 1, col});
  }
  if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
    grid[row + 1][col] = 0;
    neighbours.push_back({row + 1, col});
  }
  return neighbours;
}

void traverseNode(vector<vector<int>> &grid, int row, int col) {
  vector<vector<int>> neighbours = getNeighbours(grid, row, col);
  for (int i = 0; i < neighbours.size(); i++) {
    traverseNode(grid, neighbours[i][0], neighbours[i][1]);
  }
}

int numEnclaves(vector<vector<int>> &grid) {
  int gridSize = grid.size();
  for (int col = 0; col < grid[0].size(); col++) {
    if (grid[0][col] == 1) {
      grid[0][col] = 0;
      traverseNode(grid, 0, col);
    }
  }
  for (int col = 0; col < grid[gridSize - 1].size(); col++) {
    if (grid[gridSize - 1][col] == 1) {
      grid[gridSize - 1][col] = 0;
      traverseNode(grid, gridSize - 1, col);
    }
  }
  for (int row = 0; row < gridSize; row++) {
    if (grid[row][0] == 1) {
      grid[row][0] = 0;
      traverseNode(grid, row, 0);
    }
    if (grid[row][grid[row].size() - 1] == 1) {
      grid[row][grid[row].size() - 1] = 0;
      traverseNode(grid, row, grid[row].size() - 1);
    }
  }
  int numOfEnclaves = 0;
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      numOfEnclaves += grid[row][col];
    }
  }
  return numOfEnclaves;
}