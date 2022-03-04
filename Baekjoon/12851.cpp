#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

pii bfs_count(int s, int e) {
    vector<int> visited(100001);
    queue<pii> q;
    q.push({s, 0});
    int dist = 0;
    int methods = 0;
    while(!q.empty()) {
        pii next = q.front();
        q.pop();
        visited[next.first] = 1;
        if (next.first == e) {
            dist = next.second;
            methods++;
            while(!q.empty()) {
                pii cand = q.front();
                q.pop();
                if (cand.first == e && cand.second == next.second) methods++;
            }
        } else {
            if (next.first > 0 && visited[next.first - 1] == 0) {
                q.push({next.first - 1, next.second + 1});
            }
            if (next.first < 100000 && visited[next.first + 1] == 0) {
                q.push({next.first + 1, next.second + 1});
            }
            if (next.first <= 50000 && visited[next.first * 2] == 0) {
                q.push({next.first * 2, next.second + 1});
            }
        }
    }
    return {dist, methods};
}

int main () {
    int n, m;
    cin >> n >> m;
    pii res = bfs_count(n, m);
    cout << res.first << endl << res.second << endl;
    return 0;
}