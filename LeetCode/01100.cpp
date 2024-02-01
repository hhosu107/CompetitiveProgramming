class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    if (s.length() < k)
      return 0;
    if (k > 26)
      return 0;
    map<char, int> substring_occ;
    int char_occurrences = 0;
    int unique_substrings = 0;
    for (int i = 0; i < k; i++) {
      substring_occ[s[i]] += 1;
      if (substring_occ[s[i]] == 1)
        char_occurrences += 1;
      if (char_occurrences == k)
        unique_substrings += 1;
    }
    for (int i = k; i < s.length(); i++) {
      substring_occ[s[i - k]] -= 1;
      if (substring_occ[s[i - k]] == 0)
        char_occurrences -= 1;
      substring_occ[s[i]] += 1;
      if (substring_occ[s[i]] == 1)
        char_occurrences += 1;
      if (char_occurrences == k)
        unique_substrings += 1;
    }
    return unique_substrings;
  }
};
