class Solution {
public:
  string convertToTitle(int columnNumber) {
    string r = "";
    while (columnNumber > 0) {
      r = (char)(65 + (columnNumber - 1) % 26) + r;
      columnNumber = (columnNumber - 1) / 26;
    }
    return r;
  }
};
