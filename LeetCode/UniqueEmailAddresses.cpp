#include <set>
#include <string>
#include <vector>
using namespace std;
string getLocalName(string str);

// Time Complexity: O(mn) - m is the max len of each string
// Space Complexity: O(mn)
int numUniqueEmails(vector<string> &emails) {
  int n = emails.size();
  set<string> s;
  string domainName;
  for (int i = 0; i < n; i++) {
    domainName = emails[i].substr(emails[i].find('@'));
    s.insert(getLocalName(emails[i]) + domainName);
  }
  return s.size();
}

string getLocalName(string str) {
  int n = str.size();
  int i = 0;
  string localName = "";
  while (str[i] != '@') {
    if (str[i] == '+') {
      return localName;
    }
    if (str[i] != '.') {
      localName += str[i];
    }
    i++;
  }
  return localName;
}