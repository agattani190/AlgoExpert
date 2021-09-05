#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n) -> n is the size of s2
// Space Complexity: O(1)
bool checkInclusion(string s1, string s2) {
  int s1Size = s1.size();
  int s2Size = s2.size();
  if (s1Size > s2Size) {
    return false;
  }
  vector<int> hashTable1(26, 0);
  vector<int> hashTable2(26, 0);
  for (int i = 0; i < s1Size; i++) {
    hashTable1[s1[i] - 'a']++;
    hashTable2[s2[i] - 'a']++;
  }
  if (hashTable1 == hashTable2) {
    return true;
  }
  int rightPtr = s1Size;
  while (rightPtr < s2Size) {
    hashTable2[s2[rightPtr] - 'a']++;
    hashTable2[s2[rightPtr - s1Size] - 'a']--;
    if (hashTable1 == hashTable2) {
      return true;
    }
    rightPtr++;
  }
  return false;
}