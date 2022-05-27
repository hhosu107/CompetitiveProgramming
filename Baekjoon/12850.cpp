#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll divisor = 1000000007;
vector<vector<ll>> mat{{0, 1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 0, 0}, {1, 1, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};

vector<vector<ll>> matmul(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size()));
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            for(int k=0; k<B[0].size(); k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000000007;
            }
        }
    }
    return C;
}

vector<vector<ll>> matpow(ll n) {
    if (n == 1) {
        return mat;
    }
    vector<vector<ll>> ret = matpow(n / 2);
    ret = matmul(ret, ret);
    if (n % 2 == 1) {
        ret = matmul(ret, mat);
    }
    return ret;
}

int main () {
    ll n;
    cin >> n;
    vector<vector<ll>> ret = matpow(n);
    cout << ret[0][0] << endl;
    return 0;
}
