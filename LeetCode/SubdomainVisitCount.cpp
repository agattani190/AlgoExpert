#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> subdomainVisits(vector<string> &cpdomains) {
  unordered_map<string, int> mp;
  int n = cpdomains.size();
  int j, count;
  size_t found;
  for (int i = 0; i < n; i++) {
    j = 0;
    count = 0;
    while (cpdomains[i][j] != ' ') {
      count *= 10;
      count += (cpdomains[i][j] - '0');
      j++;
    }
    j++;
    mp[cpdomains[i].substr(j)] += count;
    found = cpdomains[i].find('.', j);
    if (found != string::npos) {
      found++;
      mp[cpdomains[i].substr(found)] += count;
    }

    found = cpdomains[i].find('.', found);
    if (found != string::npos) {
      found++;
      mp[cpdomains[i].substr(found)] += count;
    }
  }

  vector<string> result;

  for (auto it : mp) {
    result.push_back(to_string(it.second) + ' ' + it.first);
  }
  return result;
}