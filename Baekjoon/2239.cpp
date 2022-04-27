#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class sudoku_cell {
public:
  bool invalid[9] = {false};
  int invalid_count = 0;
  int value = 0;

  sudoku_cell() {}
  sudoku_cell(int value) {
    this->value = value;
    invalid_count = 8;
    for(int i=0; i<9; i++) {
      invalid[i] = (i == value - 1 ? false : true);
    }
  }
  void invalidate(int i) {
    invalid_count = (invalid[i - 1] ? invalid_count : invalid_count + 1);
    invalid[i - 1] = true;
  }
  bool assign_value() {
    if (invalid_count == 8) {
      for(int i = 0; i < 9; i++) {
        if (!invalid[i]) {
          value = i + 1;
          break;
        }
      }
      return true;
    }
    return false;
  }
  bool is_filled() {
    return value != 0;
  }
};

void invalidate_cells(vector<vector<sudoku_cell>> &grid, int row, int col) {
  int val = grid[row][col].value;
  if (val == 0) return;
  for(int i=0; i<9; i++) {
    if (i != col)
      grid[row][i].invalidate(val);
    if (i != row)
      grid[i][col].invalidate(val);
  }
  int row_box = row - (row % 3);
  int col_box = col - (col % 3);
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      if (row_box + i != row || col_box + j != col)
        grid[row_box + i][col_box + j].invalidate(val);
    }
  }
}

int fill_sudoku_once(vector<vector<sudoku_cell>> &grid) {
  int filled_count = 0;
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      if (grid[i][j].is_filled()) continue;
      if (grid[i][j].assign_value()) {
        filled_count++;
        invalidate_cells(grid, i, j);
      }
    }
  }
  return filled_count;
}

int main () {
  vector<string> sudoku_str(9);
  for(auto &x: sudoku_str) cin >> x;
  vector<vector<int>> sudoku_num(9, vector<int>(9));
  int empty_cnt = 0;
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++) {
      sudoku_num[i][j] = (int)(sudoku_str[i][j] - '0');
      empty_cnt += (sudoku_num[i][j] == 0);
    }
  }
  vector<vector<sudoku_cell>> sudoku(9, vector<sudoku_cell>(9));
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      if (sudoku_num[i][j] != 0)
        sudoku[i][j] = sudoku_cell(sudoku_num[i][j]);
    }
  }
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      invalidate_cells(sudoku, i, j);
    }
  }
  while(empty_cnt > 0) {
    int filled_count = fill_sudoku_once(sudoku);
    empty_cnt -= filled_count;
  }
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cout << sudoku[i][j].value;
    }
    cout << '\n';
  }
  return 0;
}
