class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    int dir[8][2] = {{1, 1},   {1, 0},  {1, -1}, {0, -1},
                     {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
          int nx = i + dir[k][0], ny = j + dir[k][1];
          if (0 > nx || board.size() <= nx || 0 > ny || board[0].size() <= ny)
            continue;
          if (abs(board[nx][ny]) == 1) { // since previous cells with previously
                                         // lived will be 1 or -1, use abs.
            cnt++;
          }
        }
        // live but will dead: change 1 to -1.
        if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) {
          board[i][j] = -1;
        }
        if (board[i][j] == 0 && cnt == 3) {
          board[i][j] = 2; // previously dead but now live.
        }
      }
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] > 0) {
          board[i][j] = 1;
        } else {
          board[i][j] = 0;
        }
      }
    }
  }
};

// Importance of in-place algorithm.
// Introduce two dummy values: -1 for previously live but dead, 2 for previously
// dead but live. By taking abs(cell[i][j]) == 1 for previous values, we can
// notice that the previous cell was the lived one.
