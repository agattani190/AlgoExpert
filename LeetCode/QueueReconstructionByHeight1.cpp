#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
  vector<vector<int>> copy(people);
  int n = people.size();
  int minIndex;
  int height;
  vector<vector<int>> result(n);
  for (int j = 0; j < n; j++) {
    height = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (people[i][1] == 0 && people[i][0] < height) {
        height = people[i][0];
        minIndex = i;
      }
    }
    result[j] = copy[minIndex];
    for (int i = 0; i < n; i++) {
      if (people[i][0] <= people[minIndex][0]) {
        people[i][1]--;
      }
    }
  }
  return result;
}