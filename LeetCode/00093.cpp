class Solution {
public:
  int validStoi(string s) {
    if (s.length() > 1 && s[0] == '0')
      return -1;
    int k = stoi(s);
    if (k > 255)
      return -1;
    return k;
  }
  void restoreIPAddressesKth(string s, int n, int s_len, int s_idx,
                             vector<string> &solutions, string curr_sol) {
    if (s_len - s_idx <= 0)
      return;
    if (n == 1) {
      if (s_len - s_idx > 3)
        return;
      string last = s.substr(s_idx);
      int k = validStoi(last);
      if (k == -1)
        return;
      solutions.emplace_back(curr_sol + last);
      return;
    } else {
      string next_cell = "";
      int curr_digit = 0;
      for (int i = 0; i <= 2; i++) {
        if (s_len <= s_idx + i + 1)
          continue;
        next_cell += s[s_idx + i];
        curr_digit = 10 * curr_digit + (s[s_idx + i] - '0');
        if (i == 1 && curr_digit < 10 || i == 2 && curr_digit < 100)
          continue;
        if (curr_digit > 255)
          continue;
        restoreIPAddressesKth(s, n - 1, s_len, s_idx + i + 1, solutions,
                              curr_sol + next_cell + ".");
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> solutions;
    restoreIPAddressesKth(s, 4, s.length(), 0, solutions, "");
    return solutions;
  }
};
