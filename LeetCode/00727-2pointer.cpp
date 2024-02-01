class Solution {
public:
  string minWindow(string S, string T) {
    int c = 0;

    int start = -1;
    int len = -1;

    for (int i = 0; i < S.size(); i++) {
      // go from left to right , to find the end index
      if (S[i] == T[c]) {
        c++;
      }

      // found a match
      if (c == T.size()) {
        // go from right to left , to find the  start index
        int d = i;
        while (c > 0) {
          if (T[c - 1] == S[d]) {
            c--;
          }

          d--;
        }

        if (len == -1 || i - d < len) {
          len = i - d;
          start = d + 1;
        }

        // reset the new search index to the old start position
        i = d + 1;
      }
    }

    if (len == -1)
      return "";
    return S.substr(start, len);
  }
