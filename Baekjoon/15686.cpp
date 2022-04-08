#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<int> chicken_dist(vector<pii> &houses, pii chick) {
  vector<int> dist(houses.size());
  int dist_sum = 0;
  for(int i=0; i<houses.size(); i++)
    dist[i] = abs(houses[i].first - chick.first) + abs(houses[i].second - chick.second);
  return dist;
}

vector<int> min_vector(const vector<int> l, const vector<int> r) {
  vector<int> min_v(l.size());
  for(int i=0; i<min_v.size(); i++)
    min_v[i] = min(l[i], r[i]);
  return min_v;
}

int chicken_dist(vector<pii> &houses, vector<pii> &chicks, vector<int> &selected_chicks, int s, int m, int idx) {
  if (s == 0 && idx == selected_chicks.size()) return 10000000;
  if (s == m || idx == selected_chicks.size()) {
    vector<int> min_chick_dist(houses.size(), 100);
    vector<int> default_chick_dist(houses.size(), 100);
    for(int i=0; i<selected_chicks.size(); i++) {
      vector<int> chick_dist = (selected_chicks[i] == 0 ? default_chick_dist : chicken_dist(houses, chicks[i]));
      min_chick_dist = min_vector(min_chick_dist, chick_dist);
    }
    int sum = 0;
    for(int i=0; i<houses.size(); i++)
      sum += min_chick_dist[i];
    return sum;
  }
  else {
    int unselected_sum = chicken_dist(houses, chicks, selected_chicks, s, m, idx + 1);
    selected_chicks[idx] = 1;
    int selected_sum = chicken_dist(houses, chicks, selected_chicks, s + 1, m, idx + 1);
    selected_chicks[idx] = 0;
    return min(unselected_sum, selected_sum);
  }
}

int main () {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> map(n, vector<int>(n));
  vector<pii> houses;
  vector<pii> chicks;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 1) {
        houses.push_back({i, j});
      }
      if (map[i][j] == 2) {
        chicks.push_back({i, j});
      }
    }
  }
  vector<int> selected_chicks(chicks.size());
  int sum = chicken_dist(houses, chicks, selected_chicks, 0, c, 0);
  cout << sum << endl;
  return 0;
}
