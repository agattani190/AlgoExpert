#include <vector>
using namespace std;

// Time Complexity: O(n + m) -> m is size of prerequisites
// Space Complexity: O(n + m)
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  vector<vector<int>> graph(numCourses);
  vector<int> ordering(numCourses, -1);
  vector<int> inDegree(numCourses, 0);
  int index = 0;
  for (int i = 0; i < prerequisites.size(); i++) {
    graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    inDegree[prerequisites[i][0]]++;
  }
  for (int i = 0; i < numCourses; i++) {
    if (inDegree[i] == 0) {
      ordering[index++] = i;
    }
  }
  if (index == numCourses) {
    return true;
  }
  for (int i = 0; i < numCourses; i++) {
    if (ordering[i] == -1) {
      return false;
    }
    for (int j = 0; j < graph[ordering[i]].size(); j++) {
      inDegree[graph[ordering[i]][j]]--;
      if (inDegree[graph[ordering[i]][j]] == 0) {
        ordering[index++] = graph[ordering[i]][j];
        if (index == numCourses) {
          return true;
        }
      }
    }
  }
  return true;
}