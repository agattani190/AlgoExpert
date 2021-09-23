#include <vector>
using namespace std;

// Time Complexity: O(min(height,width))
// Space Complexity: O(1)
int numberOfWaysToTraverseGraph(int width, int height) {
  int a = height + width - 2;
  int b = min(height, width) - 1;
  int result = 1;
  for (int i = 1; i <= b; i++) {
    result /= i;
    result *= (a - i + 1);
  }
  return result;
}