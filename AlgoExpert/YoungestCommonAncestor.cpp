#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

int getStepsTillRoot(AncestralTree *descendant) {
  int result = 0;
  while (descendant->ancestor != nullptr) {
    result++;
    descendant = descendant->ancestor;
  }
  return result;
}

// Time Complexity: O(k) - k is the height of the tree
// Space Complexity: O(1)
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  int stepsOne = getStepsTillRoot(descendantOne);
  int stepsTwo = getStepsTillRoot(descendantTwo);
  if (stepsTwo > stepsOne) {
    swap(stepsTwo, stepsOne);
    swap(descendantTwo, descendantOne);
  }
  int counter = stepsOne - stepsTwo;
  while (counter != 0) {
    counter--;
    descendantOne = descendantOne->ancestor;
  }
  while (descendantOne != descendantTwo) {
    descendantOne = descendantOne->ancestor;
    descendantTwo = descendantTwo->ancestor;
  }
  return descendantOne;
}