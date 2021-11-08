#include<iostream>
#include<vector>

int fibo[1000001];

using namespace std;

int main(){
  int n;
  cin >> n;
  fibo[1] = 1;
  fibo[2] = 2;
  for(int i=3; i<=n; i++){
    fibo[i] = (fibo[i-1] + fibo[i-2]) % 15746;
  }
  cout << fibo[n] << endl;
  return 0;
}
