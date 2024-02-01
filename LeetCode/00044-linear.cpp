class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;

    int tempStar = -1;
    int tempString = -1;
    while (i < s.size()) {
      if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
        j++;
        i++;
      } else if (j < p.size() && p[j] == '*') {
        tempStar = j;
        tempString = i;
        j++;
      } else if (tempStar != -1) {
        j = tempStar;
        i = tempString + 1;
        tempStar = -1;
      } else {
        return false;
      }
    }

    while (j < p.size()) {
      if (p[j] != '*')
        return false;
      j++;
    }
    return true;
  }
};

// https://www.geeksforgeeks.org/dynamic-programming-wildcard-pattern-matching-linear-time-constant-space/
