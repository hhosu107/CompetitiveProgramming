#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int op_cnt(vector<int> &broken_nums, int &aim, int rem_op, int val, int multiplier) {
  if (rem_op == 0) {
    int move_cnt = abs(aim - val);
    if (val < 10) move_cnt += 1;
    else if (val < 100) move_cnt += 2;
    else if (val < 1000) move_cnt += 3;
    else if (val < 10000) move_cnt += 4;
    else if (val < 100000) move_cnt += 5;
    else move_cnt += 6;
    return move_cnt;
  }
  else {
    int min_move_cnt = 10000000;
    for(int i=0; i<10; i++) {
      if (rem_op < 6 && i == 0 && find(broken_nums.begin(), broken_nums.end(), i) != broken_nums.end()) {
        int move_cnt = abs(aim - val) + (6 - rem_op);
        min_move_cnt = min(min_move_cnt, move_cnt);
      }
      else if (find(broken_nums.begin(), broken_nums.end(), i) == broken_nums.end()) {
        int move_cnt = op_cnt(broken_nums, aim, rem_op - 1, val + multiplier * i, multiplier * 10);
        min_move_cnt = min(min_move_cnt, move_cnt);
      }
    }
    return min_move_cnt;
  }
}

int main () {
  int aim;
  int n;
  cin >> aim >> n;
  vector<int> broken_nums = vector<int>(n);
  for(auto &b: broken_nums)
    cin >> b;
  int min_from_current = abs(aim - 100);
  int min_move_cnt = op_cnt(broken_nums, aim, 6, 0, 1);
  cout << min(min_from_current, min_move_cnt) << endl;
  return 0;
}
