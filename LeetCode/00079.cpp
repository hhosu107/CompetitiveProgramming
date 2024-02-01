class Solution {
public:
  int N, M;
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
           string &word, int char_idx, int word_len, int x, int y) {
    if (char_idx + 1 == word_len)
      return true;
    for (int i = 0; i < 4; i++) {
      int dx = x + dir[i][0];
      int dy = y + dir[i][1];
      if (0 > dx || N <= dx || 0 > dy || M <= dy)
        continue;
      if (visited[dx][dy])
        continue;
      if (word[char_idx + 1] != board[dx][dy])
        continue;
      visited[dx][dy] = true;
      bool child = dfs(board, visited, word, char_idx + 1, word_len, dx, dy);
      visited[dx][dy] = false;
      if (child)
        return true;
    }
    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    N = board.size();
    M = board[0].size();
    int word_len = word.length();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (word[0] != board[i][j])
          continue;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[i][j] = true;
        bool found = dfs(board, visited, word, 0, word_len, i, j);
        if (found)
          return true;
      }
    }
    return false;
  }
};
