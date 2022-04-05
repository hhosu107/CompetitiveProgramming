#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> grd(n, 0);
    bool zero_exist = false;
    for(auto& g: grd) {
        cin >> g;
        if (g == 0) zero_exist = true;
    }
    sort(grd.begin(), grd.end());
    int max_grd = max(grd[0] * grd[1], grd[n-2] * grd[n-1]);
    max_grd = (zero_exist ? max(0, max_grd) : max_grd);
    cout << max_grd << endl;
    return 0;
}
