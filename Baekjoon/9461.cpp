#include<iostream>
using namespace std;

using ll = long long;
long long padovan[101] = {0, 1, 1, 1, 2, 2};

int main () {
  for(int i=6; i<101; i++) {
    padovan[i] = padovan[i-1] + padovan[i-5];
  }
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    int k;
    cin >> k;
    cout << padovan[k] << endl;
  }
  return 0;
}
