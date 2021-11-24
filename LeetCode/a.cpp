#include <vector>
using namespace std;

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                         vector<vector<int>> &secondList) {
  int m = firstList.size();
  int n = secondList.size();
  vector<vector<int>> result;
  int i = 0;
  int j = 0;
  while (i < m && j < n) {
    if (firstList[i][1] <= secondList[j][1]) {
      if (firstList[i][1] >= secondList[j][0]) {
        result.push_back(
            {max(firstList[i][0], secondList[j][0]), firstList[i][1]});
      }
      i++;
    } else {
      if (secondList[j][1] >= firstList[i][0]) {
        result.push_back(
            {max(firstList[i][0], secondList[j][0]), secondList[j][1]});
      }
      j++;
    }
  }
  return result;
}