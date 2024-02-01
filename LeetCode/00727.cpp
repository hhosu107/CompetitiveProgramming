class Solution {
public:
  string minWindow(string s1, string s2) {
    // Sol) DP (s1.len * s2.len).
    // DP[s2_index][s1_index]: smallest index in x whose character equals to
    // s2[s2_index]. How to fill? loop from s2.len - 1 to 0; loop from s1.len -
    // 1 to 0.
    int s1_len = s1.length();
    int s2_len = s2.length();
    if (s1_len < s2_len)
      return "";
    vector<vector<int>> dp(s2_len, vector<int>(s1_len + 1, s1_len));
    for (int i = s2_len - 1; i >= 0; i--) {
      char tar = s2[i];
      for (int j = s1_len - 1; j >= 0; j--) {
        if (s1[j] == tar) {
          dp[i][j] = j;
        } else {
          dp[i][j] = dp[i][j + 1];
        }
      }
    } // filled next_pattern_char table.
    int temp_start;
    unordered_set<int> tried_starts;
    int best_start = 0, best_end = s1_len, best_len = s1_len + 1;
    for (int i = 0; i <= s1_len - s2_len; i++) {
      int next_idx = dp[0][i];
      if (tried_starts.find(next_idx) != tried_starts.end())
        continue;
      tried_starts.insert(next_idx);
      temp_start = next_idx;
      int next_target_idx = 1;
      while (next_target_idx < s2_len && next_idx < s1_len) {
        next_idx = dp[next_target_idx][next_idx + 1];
        if (next_idx == s1_len)
          break;
        next_target_idx += 1;
      }
      if (next_target_idx == s2_len) {
        int str_len = next_idx - temp_start + 1;
        if (best_len > str_len) {
          best_len = str_len;
          best_start = temp_start;
          best_end = next_idx;
        }
      }
    }
    if (best_len <= s1_len) {
      return s1.substr(best_start, best_end - best_start + 1);
    }
    return "";
  }
};
