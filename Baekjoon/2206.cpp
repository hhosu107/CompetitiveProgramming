#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using piiii = pair<piii, int>;

int bfs_dist(vector<string> &map, int n, int m) {
    vector<vector<vector<int>>> dist(vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(2, 9999999))));
    dist[0][0][1] = dist[0][0][0] = 0;
    queue<piiii> q;
    q.push({{{0, 0}, 0}, 1});
    int d[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
    while(!q.empty()) {
        piiii t = q.front();
        q.pop();
        if (t.first.first == make_pair(n-1, m-1)) {
            return t.first.second + 1;
        }
        else {
            for(int dx = 0; dx < 4; dx++) {
                int nx = t.first.first.first + d[0][dx];
                int ny = t.first.first.second + d[1][dx];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (map[nx][ny] == '1') {
                    if (t.second == 0) continue;
                    else if (dist[nx][ny][0] == 9999999) {
                        dist[nx][ny][0] = t.first.second + 1;
                        q.push({{{nx, ny}, t.first.second + 1}, 0});
                    }
                } else {
                    if (dist[nx][ny][t.second] == 9999999){
                        dist[nx][ny][t.second] = t.first.second + 1;
                        q.push({{{nx, ny}, t.first.second + 1}, t.second});
                    }
                }
            }
        }
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> mapp(n);
    for(auto &m: mapp) {
        cin >> m;
    }
    int res = bfs_dist(mapp, n, m);
    cout << res << '\n';
    return 0;
}