#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int maximumDetonation(vector<vector<int>> &bombs) {
  vector<vector<int>> directed_bombs(bombs.size(), vector<int>());
  vector<ll> rad_sq(bombs.size());
  for (int i = 0; i < bombs.size(); i++)
    rad_sq[i] = (ll)bombs[i][2] * (ll)bombs[i][2];
  for (int i = 0; i < bombs.size(); i++) {
    for (int j = 0; j < bombs.size(); j++) {
      if (i == j)
        continue;
      if (rad_sq[i] >=
          (ll)(bombs[i][0] - bombs[j][0]) * (ll)(bombs[i][0] - bombs[j][0]) +
              (ll)(bombs[i][1] - bombs[j][1]) * (ll)(bombs[i][1] - bombs[j][1]))
        directed_bombs[i].push_back(j);
    }
  }
  queue<int> reachable_bombs;
  vector<bool> reached;
  int max_bombs = 0;
  for (int i = 0; i < bombs.size(); i++) {
    reachable_bombs.push(i);
    reached = vector<bool>(bombs.size(), false);
    reached[i] = true;
    int bomb_cnt = 1;
    while (!reachable_bombs.empty()) {
      int cur = reachable_bombs.front();
      reachable_bombs.pop();
      for (auto next_bomb : directed_bombs[cur]) {
        if (reached[next_bomb])
          continue;
        reachable_bombs.push(next_bomb);
        reached[next_bomb] = true;
        bomb_cnt++;
      }
    }
    max_bombs = max(max_bombs, bomb_cnt);
  }
  return max_bombs;
}
