#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int minPartitions(string n) {
  int result = 1;
  for (int i = 0; i < n.size(); i++) {
    result = max(result, n[i] - '0');
  }
  return result;
}