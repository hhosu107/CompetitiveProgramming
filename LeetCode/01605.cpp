using ll = long long;
class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    /* Does greedy work? */
    vector<vector<int>> sol(rowSum.size(), vector<int>(colSum.size()));
    if (rowSum.size() == 1) {
      for (int i = 0; i < colSum.size(); i++) {
        sol[0][i] = colSum[i];
      }
      return sol;
    } else if (colSum.size() == 1) {
      for (int j = 0; j < rowSum.size(); j++) {
        sol[j][0] = rowSum[j];
      }
      return sol;
    }
    // Sol) How to compute partial sum between (x1, y1) ~ (x2, y2)?
    // We need (0, 0) ~ (x2, y2), (0, 0) ~ (x1 - 1, y2), (0, 0) ~ (x2, y1 - 1),
    // (0, 0) ~ (x1 - 1, y1 - 1). How to compute (0, 0) ~ (x, y) then? At least
    // we can compute difference between (0, 0) ~ (x, y) and (x + 1, y + 1) ~
    // (#rows - 1, #cols - 1) in O(1). (0, 0) ~ (x, y) + (x + 1, y + 1) + all =
    /*
    [5, 0, 0]
    [1, 6, 0]
    [2, 0, 8]
    */
    //[5, 4, 4], [4, 6, 3]
    // [4, 1, 0]
    // [0, 4, 0]
    // [0, 1, 3]
    vector<vector<bool>> cell_fixed(rowSum.size(),
                                    vector<bool>(colSum.size(), false));
    int diagonal_len = min(rowSum.size(), colSum.size());
    for (int i = 0; i < diagonal_len; i++) {
      sol[i][i] = min(rowSum[i], colSum[i]);
      rowSum[i] -= sol[i][i];
      colSum[i] -= sol[i][i];
    }
    for (int i = 0; i < rowSum.size(); i++) {
      for (int j = 0; j < colSum.size(); j++) {
        if (i == j)
          continue;
        sol[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i] -= sol[i][j];
        colSum[j] -= sol[i][j];
      }
    }
    return sol;
  }
};
