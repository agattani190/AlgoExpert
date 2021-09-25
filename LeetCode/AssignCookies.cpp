#include <vector>
using namespace std;

// Time Complexity: O(mlogm + nlogn)
// Space Complexity: O(1)
int findContentChildren(vector<int> &g, vector<int> &s) {
  int m = g.size();
  int n = s.size();
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int index = 0;
  int result = 0;
  for (int i = 0; i < m; i++) {
    index = lower_bound(s.begin() + index, s.end(), g[i]) - s.begin();
    if (index == n) {
      break;
    }
    result++;
    index++;
  }
  return result;
}