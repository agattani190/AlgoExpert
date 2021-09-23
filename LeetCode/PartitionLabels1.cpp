#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> partitionLabels(string s) {
  vector<int> result;
  int n = s.size();
  vector<int> lastOccurrence(26, -1);
  for (int i = 0; i < n; i++) {
    lastOccurrence[s[i] - 'a'] = i;
  }
  int prev = -1;
  int i = 0;
  int j = 0;
  while (j < n) {
    j = max(j, lastOccurrence[s[i] - 'a']);
    if (i == j) {
      result.push_back(j - prev);
      prev = j;
      j++;
    }
    i++;
  }
  return result;
}