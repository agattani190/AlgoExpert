#include <vector>
using namespace std;

// Time Complexity: O(wh) -> w, h are width and height of the matrix
// Space Complexity: O(wh)
vector<vector<int>> getNeighbours(vector<vector<int>> &matrix, int row,
                                  int col) {
  vector<vector<int>> neighbours;
  if (col > 0 && matrix[row][col - 1] == 1) {
    matrix[row][col - 1] = -1;
    neighbours.push_back({row, col - 1});
  }
  if (col < matrix[row].size() - 1 && matrix[row][col + 1] == 1) {
    matrix[row][col + 1] = -1;
    neighbours.push_back({row, col + 1});
  }
  if (row > 0 && matrix[row - 1][col] == 1) {
    matrix[row - 1][col] = -1;
    neighbours.push_back({row - 1, col});
  }
  if (row < matrix.size() - 1 && matrix[row + 1][col] == 1) {
    matrix[row + 1][col] = -1;
    neighbours.push_back({row + 1, col});
  }
  return neighbours;
}

int traverseNode(vector<vector<int>> &matrix, int row, int col,
                 int currentSize) {
  vector<vector<int>> neighbours = getNeighbours(matrix, row, col);
  for (int i = 0; i < neighbours.size(); i++) {
    currentSize++;
    currentSize =
        traverseNode(matrix, neighbours[i][0], neighbours[i][1], currentSize);
  }
  return currentSize;
}

vector<int> riverSizes(vector<vector<int>> &matrix) {
  vector<int> result;
  for (int row = 0; row < matrix.size(); row++) {
    for (int col = 0; col < matrix[row].size(); col++) {
      if (matrix[row][col] == 1) {
        matrix[row][col] = -1;
        result.push_back(traverseNode(matrix, row, col, 1));
      }
    }
  }
  return result;
}