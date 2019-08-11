#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
typedef long long int ll;
ll gcd(ll n, ll m){
  if (n == 0) return m;
  else if (m == 0) return n;
  else if (n < m) return gcd(m, n);
  else return gcd(m, n%m);
}
int main(){
  ll n, m, t;
  cin >> n >> m >> t;
  ll g = gcd(n, m);
  for(int T=1; T<=t; T++){
    ll s1, s2, e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    ll sector1 = (s2 - 1) / ((s1 == 1 ? n : m) / g), sector2 = (e2 - 1) / ((e1 == 1 ? n : m) / g);
    if(sector1 == sector2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
