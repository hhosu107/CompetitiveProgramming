#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<vector<int>>> dp;

int move_step(int curr, int num_steps, int l, int r, vector<int> &moves) {
  if (curr >= num_steps)
    return 0;
  int &ret = dp[curr][l][r]; // Use memoization. Thus every value can be updated at most once.
  if (ret != 0)
    return ret;

  ret = 1000000000; // Reset ret to enable min().

  // If one foot is not in the same spot as moves[curr], move other foot.
  // move left.
  if (moves[curr] != r) {
    int next_moves = move_step(curr + 1, num_steps, moves[curr], r, moves);
    int increment = 0;
    if (l == 0) {
      increment = 2;
    } else if (l == moves[curr]) {
      increment = 1;
    } else if ((l - moves[curr]) % 2 == 0) {
      increment = 4;
    } else {
      increment = 3;
    }
    ret = min(ret, increment + next_moves);
  }
  // If one foot is not in the same spot as moves[curr], move other foot.
  // move right.
  if (moves[curr] != l) {
    int next_moves = move_step(curr + 1, num_steps, l, moves[curr], moves);
    int increment = 0;
    if (r == 0) {
      increment = 2;
    } else if (r == moves[curr]) {
      increment = 1;
    } else if ((r - moves[curr]) % 2 == 0) {
      increment = 4;
    } else {
      increment = 3;
    }
    ret = min(ret, increment + next_moves);
  }
  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> foot(0);
  while(n != 0) {
    foot.push_back(n);
    cin >> n;
  }
  if (foot.size() < 2) {
    cout << 2 * foot.size() << '\n';
    return 0;
  }
  dp = vector<vector<vector<int>>>(foot.size(), vector<vector<int>>(5, vector<int>(5, 0)));
  int result = move_step(0, foot.size(), 0, 0, foot);
  cout << result << '\n';
  return 0;
}
