#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> m(vector<vector<int>>(n, vector<int>(n)));
    for(auto &row: m)
        for(auto &col: row)
            cin >> col;
    vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3))));
    dp[0][1][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=2; j<n; j++) {
            if (m[i][j] == 1) continue;
            for(int k=0; k<3; k++) {
                if (k == 0) {
                    dp[i][j][k] = dp[i][j-1][0] + dp[i][j-1][1];
                } else if (k == 2) {
                    if (i == 0) continue;
                    dp[i][j][k] = dp[i-1][j][2] + dp[i-1][j][1];
                } else {
                    if (i == 0) continue;
                    if (m[i-1][j] == 1 || m[i][j-1] == 1) continue;
                    dp[i][j][k] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                }
            }
        }
    }
    cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << endl;
    return 0;
}