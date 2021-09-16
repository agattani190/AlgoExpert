#include <vector>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(1)
vector<int> spiralTraverse(vector<vector<int>> &array) {
  int rows = array.size();
  int columns = array[0].size();
  vector<int> result(rows * columns, 0);
  int index = 0;
  int rowLeft = 0;
  int rowRight = rows - 1;
  int colLeft = 0;
  int colRight = columns - 1;
  while (rowLeft <= rowRight && colLeft <= colRight) {
    for (int i = colLeft; i <= colRight; i++) {
      result[index++] = array[rowLeft][i];
    }
    rowLeft++;
    if (index == rows * columns) {
      return result;
    }
    for (int i = rowLeft; i <= rowRight; i++) {
      result[index++] = array[i][colRight];
    }
    colRight--;
    if (index == rows * columns) {
      return result;
    }
    for (int i = colRight; i >= colLeft; i--) {
      result[index++] = array[rowRight][i];
    }
    rowRight--;
    if (index == rows * columns) {
      return result;
    }
    for (int i = rowRight; i >= rowLeft; i--) {
      result[index++] = array[i][colLeft];
    }
    colLeft++;
    if (index == rows * columns) {
      return result;
    }
  }
  return result;
}