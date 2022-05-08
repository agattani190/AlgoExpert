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

void traverseNode(vector<vector<int>> &matrix, int row, int col) {
  vector<vector<int>> neighbours = getNeighbours(matrix, row, col);
  for (int i = 0; i < neighbours.size(); i++) {
    traverseNode(matrix, neighbours[i][0], neighbours[i][1]);
  }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  int matrixSize = matrix.size();
  for (int col = 0; col < matrix[0].size(); col++) {
    if (matrix[0][col] == 1) {
      matrix[0][col] = -1;
      traverseNode(matrix, 0, col);
    }
  }
  for (int col = 0; col < matrix[matrixSize - 1].size(); col++) {
    if (matrix[matrixSize - 1][col] == 1) {
      matrix[matrixSize - 1][col] = -1;
      traverseNode(matrix, matrixSize - 1, col);
    }
  }
  for (int row = 0; row < matrixSize; row++) {
    if (matrix[row][0] == 1) {
      matrix[row][0] = -1;
      traverseNode(matrix, row, 0);
    }
    if (matrix[row][matrix[row].size() - 1] == 1) {
      matrix[row][matrix[row].size() - 1] = -1;
      traverseNode(matrix, row, matrix[row].size() - 1);
    }
  }
  for (int row = 0; row < matrix.size(); row++) {
    for (int col = 0; col < matrix[row].size(); col++) {
      if (matrix[row][col] == 1) {
        matrix[row][col] = 0;
      } else if (matrix[row][col] == -1) {
        matrix[row][col] = 1;
      }
    }
  }
  return matrix;
}