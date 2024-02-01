class Solution {
public:
  int titleToNumber(string columnTitle) {
    int base = 26;
    vector<int> digit_base(7, 0);
    digit_base[0] = 1;
    for (int i = 1; i <= 6; i++)
      digit_base[i] = digit_base[i - 1] * base;
    int len = columnTitle.length();
    int colnum = 0;
    for (int i = 1; i < len; i++) {
      colnum += digit_base[i];
    }
    for (int i = 0; i < len; i++) {
      int coef = (int)(columnTitle[i] - 'A');
      colnum += coef * digit_base[len - 1 - i];
    }
    return colnum + 1;
  }
};
