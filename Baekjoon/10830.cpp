#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll P = 1000;

vector<vector<ll>> matmul(vector<vector<ll>> &l, vector<vector<ll>> &r, int n){
  vector<vector<ll>> result = vector<vector<ll>>(n, vector<ll>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        result[i][j] += l[i][k] * r[k][j];
        result[i][j] %= P;
      }
    }
  }
  return result;
}

vector<vector<ll>> matpow(vector<vector<ll>> x, int n, ll b){
  vector<vector<ll>> ret = vector<vector<ll>>(n, vector<ll>(n));
  for(int i=0; i<n; i++)
    ret[i][i] = 1;
  vector<vector<ll>> base = vector<vector<ll>>(x);
  while(b > 0){
    if (b%2){
      ret = matmul(ret, base, n);
    }
    base = matmul(base, base, n);
    b /= 2;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  int n;
  ll b;
  cin >> n >> b;
  vector<vector<ll>> base = vector<vector<ll>>(n, vector<ll>(n));
  for(auto &row : base){
    for(auto &cell : row)
      cin >> cell;
  }
  vector<vector<ll>> result = matpow(base, n, b);
  for(auto row : result){
    for(auto cell : row)
      cout << cell << " ";
    cout << '\n';
  }
  return 0;
}
