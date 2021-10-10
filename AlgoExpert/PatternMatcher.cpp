#include <string>
#include <vector>
using namespace std;

pair<bool, vector<string>> check(string str, string pattern, int countX,
                                 int countY);

// Time Complexity: O(n^2 + m)
// Space Complexity: O(n)
vector<string> patternMatcher(string pattern, string str) {
  int n = str.size();
  int m = pattern.size();
  if (m == 0) {
    return {};
  }
  int countX = 0;
  int countY = 0;
  for (auto i : pattern) {
    if (i == 'x') {
      countX += 1;
    } else {
      countY += 1;
    }
  }

  for (int i = min(countX, countY); i > 1; i--) {
    if (countX % i == 0 && countY % i == 0) {
      if (n % i != 0) {
        return {};
      } else {
        countX /= i;
        countY /= i;
        n /= i;
      }
    }
  }

  bool exchanged = false;
  if (countY > countX) {
    swap(countX, countY);
    exchanged = true;
  }

  if (countY == 0) {
    string s1 = str.substr(0, n / countX);
    string s = "";
    for (int i = 0; i < countX; i++) {
      s += s1;
    }
    if (s.compare(str) == 0) {
      if (exchanged) {
        return {"", s1};
      }
      return {s1, ""};
    }
    return {};
  }

  for (int i = 1; i < n / countX + 1; i++) {
    pair<bool, vector<string>> temp;
    if (exchanged) {
      temp = check(str, pattern, (n - countX * i) / countY, i);
    } else {
      temp = check(str, pattern, i, (n - countX * i) / countY);
    }
    if (temp.first) {
      return {temp.second[0], temp.second[1]};
    }
  }
  return {};
}

pair<bool, vector<string>> check(string str, string pattern, int countX,
                                 int countY) {
  int m = pattern.size();
  string s = "";
  string s1 = "";
  string s2 = "";
  bool otherComputed = false;
  if (pattern[0] == 'x') {
    s1 = str.substr(0, countX);
    s = s1;
    for (int i = 1; i < m; i++) {
      if (pattern[i] == 'x') {
        s += s1;
      } else {
        if (!otherComputed) {
          otherComputed = true;
          s2 = str.substr(s.size(), countY);
        }
        s += s2;
      }
    }
  } else {
    s2 = str.substr(0, countY);
    s = s2;
    for (int i = 1; i < m; i++) {
      if (pattern[i] == 'y') {
        s += s2;
      } else {
        if (!otherComputed) {
          otherComputed = true;
          s1 = str.substr(s.size(), countX);
        }
        s += s1;
      }
    }
  }
  if (s.compare(str) == 0) {
    return {true, {s1, s2}};
  }
  return {false, {}};
}