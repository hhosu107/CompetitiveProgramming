#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

// Ghost: nothing can block ghost, so the distance from ghost to the door is
// euclidean distance.
// Whereas a person is blocked by walls, so use bfs to the find the distance.
// After finding them, compare the distances.
using pii = pair<int, int>;
using ppi = pair<pii, int>;
int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs(pii s, pii e, vector<string> &map, int n, int m, bool ghost) {
    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    if (s == e) return 0;
    queue<ppi> q;
    q.push({s, 0});
    visited[s.first][s.second] = true;
    while(!q.empty()) {
        ppi c = q.front();
        q.pop();
        if (c.first == e) {
            return c.second;
        }
        for(int i=0; i<4; i++) {
            int nx = c.first.first + dd[i][0];
            int ny = c.first.second + dd[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!ghost && map[nx][ny] == '#') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, c.second + 1});
        }
    }
    return -1;
}

int main () {
    // 1. Take distance from person to exit. If it is -1, print no.
    // 2. Take distance from person to ghosts. If it is -1, skip that one.
    // 3. Take distance from each ghost to exit. If any ghost can reach faster than or equal to the person, print no.
    // 4. o.w., print yes.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for(int i=0; i<n; i++)
        cin >> map[i];
    pii N;
    pii G;
    pii E;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (map[i][j] == 'N')
                N = make_pair(i, j);
            if (map[i][j] == 'D')
                E = make_pair(i, j);
        }
    }
    int nd = bfs(N, E, map, n, m, false);
    if (nd == -1) {
        cout << "No\n";
        return 0;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (map[i][j] != 'G') continue;
            G = make_pair(i, j);
            int ng = abs(E.first - G.first) + abs(E.second - G.second);
            if (ng <= nd) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
