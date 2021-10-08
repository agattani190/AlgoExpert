#include <string>
#include <vector>
using namespace std;

class Trie {
public:
  Trie() {
    this->isLeaf = false;
    this->children = vector<Trie *>(26, NULL);
  }

  // Time Complexity: O(n) - w is the length of word
  // Space Complexity: O(n)
  void insert(string word) {
    Trie *root = this;
    for (auto w : word) {
      if (root->children[w - 'a'] == NULL)
        root->children[w - 'a'] = new Trie();
      root = root->children[w - 'a'];
    }
    root->isLeaf = true;
  }

  // Time Complexity: O(n) - w is the length of word
  // Space Complexity: O(1)
  bool search(string word) {
    Trie *root = this;
    for (auto w : word) {
      root = root->children[w - 'a'];
      if (root == NULL)
        return false;
    }
    return root->isLeaf;
  }

  // Time Complexity: O(p) - p is the length of prefix
  // Space Complexity: O(1)
  bool startsWith(string prefix) {
    Trie *root = this;
    for (auto p : prefix) {
      root = root->children[p - 'a'];
      if (root == NULL)
        return false;
    }
    return true;
  }

private:
  bool isLeaf;
  vector<Trie *> children;
};