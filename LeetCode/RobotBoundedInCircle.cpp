#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isRobotBounded(string instructions) {
  int count = 0;
  int direction = 1;
  int x = 0;
  int y = 0;
  for (auto i : instructions) {
    if (i == 'L') {
      direction++;
      if (direction > 4) {
        direction -= 4;
      }
      count++;
    } else if (i == 'R') {
      count--;
      direction--;
      if (direction < 1) {
        direction += 4;
      }
    } else {
      if (direction == 1) {
        y++;
      } else if (direction == 2) {
        x--;
      } else if (direction == 3) {
        y--;
      } else {
        x++;
      }
    }
  }

  count = count % 4;
  if (count != 0) {
    return true;
  } else {
    return x == 0 && y == 0;
  }
}