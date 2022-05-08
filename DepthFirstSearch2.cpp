#include <stack>
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
  vector<string> depthFirstSearch(vector<string> *array) {
    stack<Node *> st;
    st.push(this);
    while (!st.empty()) {
      Node *curr = st.top();
      st.pop();
      array->push_back(curr->name);
      for (int i = curr->children.size() - 1; i >= 0; i--) {
        st.push(curr->children[i]);
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
