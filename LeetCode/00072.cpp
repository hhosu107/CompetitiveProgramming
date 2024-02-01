class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> d = vector<vector<int>>(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      d[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
      d[0][j] = j;
    }
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= m; i++) {
        if (word1[i - 1] == word2[j - 1]) {
          d[i][j] = d[i - 1][j - 1];
        } else {
          d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
        }
      }
    }
    return d[m][n];
  }
};
