#include<bits/stdc++.h>

using namespace std;

using aii = array<array<int, 20>, 20>;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

piii min_distance_fish(int &n, aii &field, pii &start, int &size) {
  aii dists;
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      dists[i][j] = 1000;
    }
  }
  dists[start.first][start.second] = 0;
  queue<pii> q;
  q.push(start);
  pii curr = q.front();
  bool fishable = false;
  while(!q.empty()) {
    curr = q.front();
    q.pop();
    if (field[curr.first][curr.second] != 0 && field[curr.first][curr.second] < size) {
      fishable = true;
      break;
    }
    int dist = dists[curr.first][curr.second];
    for(int i=0; i<4; i++) {
      pii next = {curr.first + dx[i], curr.second + dy[i]};
      if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) {
        if (field[next.first][next.second] <= size && dists[next.first][next.second] > dist + 1) {
          dists[next.first][next.second] = dist + 1;
          q.push(next);
        }
      }
    }
  }
  while(!q.empty()) {
    pii cand = q.front();
    q.pop();
    if (field[cand.first][cand.second] == 0 || field[cand.first][cand.second] >= size)
      continue;
    if (dists[cand.first][cand.second] != dists[curr.first][curr.second])
      continue;
    if (curr.first > cand.first || (curr.first == cand.first && curr.second > cand.second)) {
      curr = cand;
    }
  }
  if (!fishable) return {{-1, -1}, 1000};
  return {curr, dists[curr.first][curr.second]};
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  aii x;
  int n;
  cin >> n;
  pii bs = {0, 0};
  for(int i=0; i<20; i++) {
    for(int j=0; j<20; j++) {
      if (i < n && j < n) {
        cin >> x[i][j];
      } else x[i][j] = 1000;
      if (x[i][j] == 9) {
        bs = {i, j};
        x[i][j] = 0;
      }
    }
  }
  int bs_size = 2;
  int size_buffer = 0;
  int hunt_time = 0;
  while(1) {
    piii fish = min_distance_fish(n, x, bs, bs_size);
    if (fish.first.first == -1) {
      break;
    } else {
      bs = fish.first;
      size_buffer++;
      if (size_buffer == bs_size) {
        bs_size++;
        size_buffer = 0;
      }
      hunt_time += fish.second;
      x[bs.first][bs.second] = 0;
    }
  }
  cout << hunt_time << '\n';
  return 0;
}
