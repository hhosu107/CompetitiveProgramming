#include<bits/stdc++.h>
using namespace std;

/* small: brute force. But somehow this fails. */
void grid_search(int t) {
    int R, C;
    cin >> R >> C;
    vector<string> maps(R);
    for(string &row: maps) {
        cin >> row;
    }
    vector<vector<int>> distance_map(R, vector<int>(C, 999));
    
    int original_max_dist = -1;
    int dist_gain = 0;
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if (maps[r][c] == '1') {
                for(int i=0; i<R; i++) {
                    for(int j=0; j<C; j++) {
                        distance_map[i][j] = min(distance_map[i][j], abs(r-i) + abs(c-j));
                    }
                }
            }
        }
    }
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            original_max_dist = max(original_max_dist, distance_map[r][c]);
        }
    }
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            vector<vector<int>> updated_distance_map = distance_map;
            int updated_max_dist = -1;
            for(int i=0; i<R; i++) {
                for(int j=0; j<C; j++) {
                    updated_distance_map[i][j] = min(updated_distance_map[i][j], abs(r-i) + abs(c-j));
                    updated_max_dist = max(updated_max_dist, updated_distance_map[i][j]);
                }
            }
            dist_gain = max(dist_gain, max(0, original_max_dist - updated_max_dist));
        }
    }
    cout << "Case #" << t << ": " << dist_gain << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        grid_search(t);
    }
    return 0;
}
