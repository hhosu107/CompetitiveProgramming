#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int _gcd(int a, int b){
  if(a < b) return _gcd(b, a);
  if(a == 0) return b;
  if(b == 0) return a;
  if(a % b == 0) return b;
  return _gcd(b, a%b);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> s = vector<int>(n);
  int maxi = -1;
  for(int i=0; i<n; i++){
    scanf("%d", &s[i]);
    if(s[i] > maxi) maxi = s[i];
  }
  vector<int> dif = vector<int>(n);
  for(int i=0; i<n; i++){
    dif[i] = maxi - s[i];
  }
  int idx = 0;
  for(int i=0; i<n; i++){
    if(dif[i] != 0){
      idx = i;
      break;
    }
  }
  int gcd = dif[idx];
  for(int i=idx; i<n-1; i++){
    if(dif[i+1] == 0) continue;
    gcd = _gcd(gcd, dif[i+1]);
  }
  long long int people = 0;
  for(int i=0; i<n; i++){
    people += (dif[i] / gcd);
  }
  cout << people << " " << gcd << "\n";
  return 0;
}
