#include <queue>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  // Time Complexity: O(V+E) -> V and E are number of vertices and edges
  // Space Complexity: O(V)
  vector<string> breadthFirstSearch(vector<string> *array) {
    queue<Node *> q;
    q.push(this);
    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();
      array->push_back(curr->name);
      for (int i = 0; i < curr->children.size(); i++) {
        q.push(curr->children[i]);
      }
    }
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
