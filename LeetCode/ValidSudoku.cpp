#include <vector>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
bool isValidSudoku(vector<vector<char>> &board) {
  vector<bool> validity(9, false);
  int num;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        num = board[i][j] - '1';
        if (validity[num]) {
          return false;
        }
        validity[num] = true;
      }
    }
    for (int k = 0; k < 9; k++) {
      validity[k] = false;
    }
    for (int j = 0; j < 9; j++) {
      if (board[j][i] != '.') {
        num = board[j][i] - '1';
        if (validity[num]) {
          return false;
        }
        validity[num] = true;
      }
    }
    for (int k = 0; k < 9; k++) {
      validity[k] = false;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int l = 0; l < 3; l++) {
        if (board[3 * i + l][3 * j] != '.') {
          num = board[3 * i + l][3 * j] - '1';
          if (validity[num]) {
            return false;
          }
          validity[num] = true;
        }
        if (board[3 * i + l][3 * j + 1] != '.') {
          num = board[3 * i + l][3 * j + 1] - '1';
          if (validity[num]) {
            return false;
          }
          validity[num] = true;
        }
        if (board[3 * i + l][3 * j + 2] != '.') {
          num = board[3 * i + l][3 * j + 2] - '1';
          if (validity[num]) {
            return false;
          }
          validity[num] = true;
        }
      }
      for (int k = 0; k < 9; k++) {
        validity[k] = false;
      }
    }
  }
  return true;
}