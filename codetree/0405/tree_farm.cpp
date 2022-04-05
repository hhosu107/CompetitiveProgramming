#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<vector<int>>> dpbin;
vector<vector<int>> berries;

int main () {
    int n;
    cin >> n;
    berries = vector<vector<int>>(n, vector<int>(n));
    for(auto &br: berries) {
        for(auto &bc: br)
            cin >> bc;
    }
    dpbin = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
    dpbin[0][0][0] = berries[0][0];
    dpbin[0][0][1] = berries[0][0] * 2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<2; k++){ 
                if (i + j == 0) continue;
                if (i == 0) {
                    dpbin[i][j][k] = dpbin[i][j-1][k] + berries[i][j];
                    if (k == 1) {
                        dpbin[i][j][k] = max(dpbin[i][j-1][0] + 2 * berries[i][j], dpbin[i][j][k]);
                    }
                } else if (j == 0) {
                    dpbin[i][j][k] = dpbin[i-1][j][k] + berries[i][j];
                    if (k == 1) {
                        dpbin[i][j][k] = max(dpbin[i-1][j][0] + 2 * berries[i][j], dpbin[i][j][k]);
                    }
                } else {
                    dpbin[i][j][k] = max(dpbin[i][j-1][k], dpbin[i-1][j][k]) + berries[i][j];
                    if (k == 1) {
                        dpbin[i][j][k] = max(dpbin[i][j][k], max(dpbin[i][j-1][0], dpbin[i-1][j][0]) + 2 * berries[i][j]);
                    }
                }
            }
        }
    }
    cout << dpbin[n-1][n-1][1] << endl;
    return 0;
}
