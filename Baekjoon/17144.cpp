#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
int dd[5][2] = {{0, 0}, {1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vector<vector<int>> dust_vapor(vector<vector<int>> &dusts, pii cl[2], int r, int c) {
    vector<vector<int>> next_dust(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if (dusts[i][j] == -1) {
                next_dust[i][j] = -1;
                continue;
            }
            int vapor_cnt = 0;
            for(int a=1; a<=4; a++) {
                int nx = i + dd[a][0], ny = j + dd[a][1];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (make_pair(nx, ny) == cl[0] || make_pair(nx, ny) == cl[1]) continue;
                next_dust[nx][ny] += dusts[i][j] / 5;
                vapor_cnt++;
            }
            next_dust[i][j] += dusts[i][j];
            next_dust[i][j] -= (dusts[i][j] / 5) * vapor_cnt;
        }
    }
    return next_dust;
}

vector<vector<int>> air_move(vector<vector<int>> &dusts, vector<vector<int>> &airmap, pii cl[2], int r, int c) {
    vector<vector<int>> next_dust(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            next_dust[i][j] += dusts[i][j];
            if (airmap[i][j] == 0) continue;
            int nx = i + dd[airmap[i][j]][0], ny = j + dd[airmap[i][j]][1];
            int dust = dusts[i][j];
            next_dust[i][j] -= dust;
            if (make_pair(nx, ny) == cl[0] || make_pair(nx, ny) == cl[1]) continue;
            next_dust[nx][ny] += dust;
        }
    }
    return next_dust;
}

int main () {
    int r, c, t;
    cin >> r >> c >> t;
    vector<vector<int>> dusts(r, vector<int>(c, 0));
    pii cl[2];
    int found_cl = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> dusts[i][j];
            if (dusts[i][j] == -1) {
                cl[found_cl++] = make_pair(i, j);
            }
        }
    }
    vector<vector<int>> airmap(r, vector<int>(c));
    for(int i=1; i<c-1; i++) {
        airmap[cl[0].first][i] = 4;
        airmap[cl[1].first][i] = 4;
    }
    for(int i=0; i<cl[0].first; i++) {
        airmap[i][0] = 1;
        airmap[i+1][c-1] = 3;
    }
    for(int i=r-1; i>cl[1].first; i--) {
        airmap[i][0] = 3;
        airmap[i-1][c-1] = 1;
    }
    for(int i=c-1; i>=1; i--) {
        airmap[0][i] = airmap[r-1][i] = 2;
    }
    while(t--) {
        vector<vector<int>> next_dust = dust_vapor(dusts, cl, r, c);
        dusts = next_dust;
        vector<vector<int>> vap_dust = air_move(dusts, airmap, cl, r, c);
        dusts = vap_dust;
    }
    dusts[cl[0].first][cl[0].second] = 0;
    dusts[cl[1].first][cl[1].second] = 0;
    int dust_sum = 0;
    for(auto row: dusts) {
        for(auto col: row) {
            dust_sum += col;
        }
    }
    cout << dust_sum << endl;
    return 0;
}