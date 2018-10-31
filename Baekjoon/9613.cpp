#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long int gcd(long long int a, long long int b){
  if(a < b) swap(a, b);
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}
long long int lcm(long long int &a, long long int &b){
  return a * b / gcd(a, b);
}
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int t=0; t<T; t++){
    int N;
    cin >> N;
    vector<long long int> num(N, 0);
    for(int i=0; i<N; i++) cin >> num[i];
    long long int res = 0;
    for(int i=0; i<N-1; i++){
      for(int j=i+1; j<N; j++)
        res += gcd(num[i], num[j]);
    }
    cout << res << '\n';
  }
  return 0;
}
