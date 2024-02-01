class Solution {
public:
  int shortestWay(string word1, string word2) {
    vector<vector<int>> indices(word1.length(), vector<int>(26));
    indices[word1.length() - 1][word1[word1.length() - 1] - 'a'] =
        word1.length();
    for (int i = word1.length() - 2; i >= 0; i--) {
      indices[i] = vector<int>(indices[i + 1]);
      indices[i][word1[i] - 'a'] = i + 1;
    }
    int j = 0, res = 1;
    for (int i = 0; i < word2.length(); i++) {
      if (j == word1.length()) {
        j = 0;
        res += 1;
      }
      j = indices[j][word2[i] - 'a'];
      if (indices[0][word2[i] - 'a'] == 0)
        return -1; // invalid; next concatenation is impossible.
      if (j == 0) {
        res += 1;
        i--;
      }
    }
    return res;
  }
};

// https://leetcode.com/problems/shortest-way-to-form-string/discuss/330938/Accept-is-not-enough-to-get-a-hire.-Interviewee-4-follow-up
/*
public int shortestWay(String source, String target) {
    char[] cs = source.toCharArray();
    char[] ts = target.toCharArray();
    int[][] idx = new int[cs.length][26];
    idx[cs.length - 1][cs[cs.length - 1] - 'a'] = cs.length;
    for (int i = cs.length - 2; i >= 0; i--) {
        idx[i] = Arrays.copyOf(idx[i + 1],26);
        idx[i][cs[i] - 'a'] = i + 1;
    }
    int j = 0, res = 1;
    for (int i = 0; i < ts.length; i++) {
        if (j == cs.length) {
            j = 0;
            res++;
        }
        j = idx[j][ts[i] - 'a'];
        if (idx[0][ts[i] - 'a'] == 0) return -1;
        if (j == 0) {
            res++;
            i--;
        }
    }
    return res;
}
*/
