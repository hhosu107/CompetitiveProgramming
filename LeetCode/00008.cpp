class Solution {
public:
  int myAtoi(string s) {
    int idx = 0;
    while (s[idx] == ' ')
      idx++;
    bool sign = true;
    if (s.length() > idx && s[idx] == '-') {
      sign = false;
      idx++;
    } else if (s.length() > idx && s[idx] == '+') {
      idx++;
    }
    long long int bound_min = -(1LL << 31) - 1;
    long long int bound_max = (1LL << 31);
    long long int val = 0;
    while (s[idx] >= '0' && s[idx] <= '9' && val < (1LL << 32)) {
      val = 10 * val + (long long int)(s[idx] - '0');
      idx += 1;
    }
    if (!sign)
      val = -val;
    if (val <= bound_min)
      val = bound_min + 1;
    if (val >= bound_max)
      val = bound_max - 1;
    return (int)val;
  }
};
// Real answer: despite comparing with INT_MAX, use INT_MAX/10 to rule in 32-bit
// bound.
