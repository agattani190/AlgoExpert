#include <unordered_map>
#include <vector>
using namespace std;

vector<int> getPrimeFactors(int n);
int find(int x, vector<int> &tree);
void unite(int u, int v, vector<int> &tree, vector<int> &rank);

// Average Time Complexity: O(max + n(sqrt(max) +log(max)))
// Space Complexity: O(max+n)
// max is the maximum value in nums
int largestComponentSize(vector<int> &nums) {
  int n = nums.size();
  vector<int> primeFactors;
  unordered_map<int, int> mp;
  int maxNum = nums[max_element(nums.begin(), nums.end()) - nums.begin()];
  vector<int> tree(maxNum + 1);
  vector<int> rank(maxNum + 1);
  for (int i = 0; i < maxNum + 1; i++) {
    tree[i] = i;
    rank[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    primeFactors = getPrimeFactors(nums[i]);
    mp[nums[i]] = primeFactors[0];
    for (int i = 1; i < primeFactors.size(); i++) {
      unite(primeFactors[i - 1], primeFactors[i], tree, rank);
    }
  }
  unordered_map<int, int> mp1;
  int result = 0;
  int parent;
  for (int i = 0; i < n; i++) {
    parent = find(mp[nums[i]], tree);
    mp1[parent]++;
    result = max(result, mp1[parent]);
  }
  return result;
}

vector<int> getPrimeFactors(int n) {
  if (n == 1) {
    return {1};
  }
  int primeFactor = 2;
  vector<int> primeFactors;
  while (n >= primeFactor * primeFactor) {
    if (n % primeFactor) {
      primeFactor++;
    } else {
      primeFactors.push_back(primeFactor);
      while (n % primeFactor == 0) {
        n /= primeFactor;
      }
    }
  }
  if (n > 1) {
    primeFactors.push_back(n);
  }
  return primeFactors;
}

int find(int x, vector<int> &tree) {
  if (x == tree[x]) {
    return x;
  }
  tree[x] = find(tree[x], tree);
  return tree[x];
}

void unite(int u, int v, vector<int> &tree, vector<int> &rank) {
  int x = find(u, tree);
  int y = find(v, tree);
  if (rank[x] < rank[y]) {
    tree[x] = y;
  } else if (rank[x] > rank[y]) {
    tree[y] = x;
  } else {
    rank[x]++;
    tree[y] = x;
  }
}