#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
char slowestKey(vector<int> &releaseTimes, string keysPressed) {
  vector<int> lower(26, 0);
  lower[keysPressed[0] - 'a'] = releaseTimes[0];
  for (int i = 1; i < keysPressed.size(); i++) {
    lower[keysPressed[i] - 'a'] =
        max(releaseTimes[i] - releaseTimes[i - 1], lower[keysPressed[i] - 'a']);
  }
  int maxTime = 0;
  char result;
  for (int i = 25; i >= 0; i--) {
    if (lower[i] > maxTime) {
      maxTime = lower[i];
      result = 'a' + i;
    }
  }
  return result;
}