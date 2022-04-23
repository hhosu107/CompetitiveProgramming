#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    int n, m, r;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> r;
    vector<int> items(n);
    for(auto &x: items) cin >> x;
    vector<vector<int>> edges(n, vector<int>(n, 10000));
    int a, b;
    for(int i=0; i<r; i++) {
        cin >> a >> b;
        cin >> edges[a-1][b-1];
        edges[b-1][a-1] = edges[a-1][b-1];
    }
    vector<vector<int>> distance(edges);
    for(int i=0; i<n; i++) distance[i][i] = 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    int max_items = 0;
    for(int i=0; i<n; i++) {
        int sum_items = 0;
        for(int j=0; j<n; j++) {
            if (distance[i][j] <= m) sum_items += items[j];
        }
        max_items = max(max_items, sum_items);
    }
    cout << max_items << '\n';
    return 0;
}