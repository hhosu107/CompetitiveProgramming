#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> move_cell_direction(vector<vector<int>> board, int direction) {
  vector<vector<int>> new_board(board.size(), vector<int>(board[0].size()));
  int delta;
  int start, end;
  if (direction == 0 || direction == 1) {
    delta = -1;
    start = board.size() - 1;
    end = -1;
  } else {
    delta = 1;
    start = 0;
    end = board.size();
  }
  if (direction == 0 || direction == 2) {
    for(int i=0; i<board.size(); i++) {
      int unfinished_index = start;
      for(int j=start; (start <= end ? j < end : j > end); j += delta) {
        if (board[i][j] == 0) {
          continue;
        } else if (new_board[i][unfinished_index] == 0) {
          new_board[i][unfinished_index] = board[i][j];
        } else if (new_board[i][unfinished_index] == board[i][j]) {
          new_board[i][unfinished_index] *= 2;
          unfinished_index += delta;
        } else {
          unfinished_index += delta;
          new_board[i][unfinished_index] = board[i][j];
        }
      }
    }
  } else {
    for(int j=0; j<board.size(); j++) {
      int unfinished_index = start;
      for(int i=start; (start <= end ? i < end : i > end); i += delta) {
        if (board[i][j] == 0) {
          continue;
        } else if (new_board[unfinished_index][j] == 0) {
          new_board[unfinished_index][j] = board[i][j];
        } else if (new_board[unfinished_index][j] == board[i][j]) {
          new_board[unfinished_index][j] *= 2;
          unfinished_index += delta;
        } else {
          unfinished_index += delta;
          new_board[unfinished_index][j] = board[i][j];
        }
      }
    }
  }
  return new_board;
}

int move_cell_max(vector<vector<int>> board, int left_try) {
  if (left_try == 0) {
    int max_cell = 0;
    for(vector<int> row: board) {
      for(int cell: row) {
        max_cell = max(max_cell, cell);
      }
    }
    return max_cell;
  }
  int max_cell = 0;
  for(int i=0; i<4; i++) {
    vector<vector<int>> direction_result = move_cell_direction(board, i);
    max_cell = max(max_cell, move_cell_max(direction_result, left_try - 1));
  }
  return max_cell;
}

int main () {
  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  for(vector<int> &r: board) {
    for(int &c: r)
      cin >> c;
  }
  /*
  if (n == 1) {
    cout << board[0][0] << endl;
    return 0;
  }
  */
  int max_cell = move_cell_max(board, 5);
  cout << max_cell << endl;
  return 0;
}
