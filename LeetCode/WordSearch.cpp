#include <string>
#include <vector>
using namespace std;

bool existHelper(vector<vector<char>> &board, string word, int startIndex,
                 int row, int col);

// Time Complexity: O(mn*3^s) - s is the size of word
// Space Complexity: O(s)
bool exist(vector<vector<char>> &board, string word) {
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (existHelper(board, word, 0, i, j)) {
        return true;
      }
    }
  }
  return false;
}

bool existHelper(vector<vector<char>> &board, string word, int startIndex,
                 int row, int col) {
  if (startIndex == word.size()) {
    return true;
  }
  if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
      board[row][col] != word[startIndex]) {
    return false;
  } else {
    board[row][col] = '.';
    bool doesExist = false;
    doesExist = existHelper(board, word, startIndex + 1, row + 1, col);
    if (doesExist) {
      board[row][col] = word[startIndex];
      return true;
    }
    doesExist = existHelper(board, word, startIndex + 1, row - 1, col);
    if (doesExist) {
      board[row][col] = word[startIndex];
      return true;
    }
    doesExist = existHelper(board, word, startIndex + 1, row, col + 1);
    if (doesExist) {
      board[row][col] = word[startIndex];
      return true;
    }
    doesExist = existHelper(board, word, startIndex + 1, row, col - 1);
    if (doesExist) {
      board[row][col] = word[startIndex];
      return true;
    }
  }
  board[row][col] = word[startIndex];
  return false;
}