#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> minOperations(string boxes) {
  int n = boxes.size();
  vector<int> result(n);
  int step = 0;
  int ball = 0;
  for (int i = n - 1; i >= 0; i--) {
    result[i] = step;
    if (boxes[i] == '1') {
      ball++;
    }
    step += ball;
  }
  step = 0;
  ball = 0;
  for (int i = 0; i < n; i++) {
    result[i] += step;
    if (boxes[i] == '1') {
      ball++;
    }
    step += ball;
  }
  return result;
}