#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10]; // c[i][j] saves whether ith row contains j.
bool c2[10][10]; // c2[i][j] saves whether ith column contains j.
bool c3[10][10]; // c3[i][j] saves whether ith square contains j.
int n=9;
int cnt=0;
int square(int x, int y) {
    return (x/3)*3+(y/3); // square index computing.
}
bool go(int z) {
    cnt += 1;
    if (cnt >= 10000000) {
        return true;
    }
    if (z == 81) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z/n;
    int y = z%n;
    if (a[x][y] != 0) { // We already know the cell value.
        return go(z+1);
    } else {
        for (int i=1; i<=9; i++) { // For lexicographically fastest sudoku.
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) { // Only if ith row, column, and square doesn't contain i, try i.
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if (go(z+1)) { // If found a valid result, return true.
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false; // Revert.
            }
        }
    }
    return false;
}
int main() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i,j)][a[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
