class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    reverse(digits.begin(), digits.end());
    int carry = 0;
    for (int i = 0; i < digits.size(); i++) {
      int increment = digits[i] + 1;
      if (increment >= 10) {
        digits[i] = 0;
        carry = 1;
      } else {
        digits[i] = increment;
        carry = 0;
        break;
      }
    }
    if (carry == 1) {
      digits.push_back(1);
    }
    reverse(digits.begin(), digits.end());
    return digits;
  }
};
