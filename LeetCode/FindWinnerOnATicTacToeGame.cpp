#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
string tictactoe(vector<vector<int>> &moves) {
  int n = moves.size();
  vector<int> isMarked(9, 0);
  bool gameWon = false;
  int i = 1;
  if (n % 2) {
    i = 0;
  }
  for (; i < n; i += 2) {
    isMarked[moves[i][0] * 3 + moves[i][1]] = 1;
  }
  if ((isMarked[0] && isMarked[1] && isMarked[2]) ||
      (isMarked[3] && isMarked[4] && isMarked[5]) ||
      (isMarked[6] && isMarked[7] && isMarked[8]) ||
      (isMarked[0] && isMarked[3] && isMarked[6]) ||
      (isMarked[1] && isMarked[4] && isMarked[7]) ||
      (isMarked[2] && isMarked[5] && isMarked[8]) ||
      (isMarked[0] && isMarked[4] && isMarked[8]) ||
      (isMarked[2] && isMarked[4] && isMarked[6])) {
    gameWon = true;
  }
  if (gameWon) {
    return n % 2 ? "A" : "B";
  } else {
    return n == 9 ? "Draw" : "Pending";
  }
}