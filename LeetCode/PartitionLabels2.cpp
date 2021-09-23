#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)
vector<int> partitionLabels(string s) {
  vector<int> result;
  int n = s.size();
  int i = 0;
  int j = 0;
  int prev = -1;
  size_t found;
  while (j < n - 1) {
    found = s.find(s[i], j + 1);
    if (found != string::npos) {
      j = found;
    } else {
      if (i == j) {
        result.push_back(j - prev);
        prev = j;
        j++;
      }
      i++;
    }
  }
  result.push_back(j - prev);
  return result;
}