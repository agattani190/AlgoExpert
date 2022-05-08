#include <vector>
using namespace std;

// Time Complexity: O(mlogn) -> m,n are number of rows and columns
// Space Complexity: O(1)
vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  int rows = matrix.size();
  int leftPtr, rightPtr, midPtr;
  for (int i = 0; i < rows; i++) {
    leftPtr = 0;
    rightPtr = matrix[i].size() - 1;
    if (target < matrix[i][leftPtr]) {
      return {-1, -1};
    } else if (target <= matrix[i][rightPtr]) {
      while (leftPtr <= rightPtr) {
        midPtr = leftPtr + ((rightPtr - leftPtr) / 2);
        if (matrix[i][midPtr] == target) {
          return {i, midPtr};
        } else if (matrix[i][midPtr] < target) {
          leftPtr = midPtr + 1;
        } else {
          rightPtr = midPtr - 1;
        }
      }
    }
  }
  return {-1, -1};
}