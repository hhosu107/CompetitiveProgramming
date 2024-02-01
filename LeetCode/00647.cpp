class Solution {
public:
  int countSubstrings(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length()));
    int p_count = 0;
    for (int i = 0; i < s.length(); i++) {
      dp[i][i] = 1;
      p_count += 1;
    }
    for (int i = 1; i < s.length(); i++) {
      dp[i - 1][i] = (s[i - 1] == s[i] ? 1 : 0);
      p_count += dp[i - 1][i];
    }
    for (int i = s.length() - 3; i >= 0; i--) {
      for (int j = i + 2; j < s.length(); j++) {
        dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] : 0);
        p_count += dp[i][j];
      }
    }
    return p_count;
  }
};
