/*
500000000000000000 500000000000000002 -> 11
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0LL) return a;
    return gcd(b, a % b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll gc = gcd(a, b);
    string s(gc, '1');
    cout << s << endl;
    return 0;
}
