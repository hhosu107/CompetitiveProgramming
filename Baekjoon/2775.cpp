#include<iostream>
using namespace std;
int peoples[15][15];

int main () {
  int t;
  int k, n;
  for(int i=1; i<=14; i++)
    peoples[0][i] = i;
  int partialsum = 0;
  for(int i=1; i<=14; i++){
    partialsum = 0;
    for(int j=1; j<=14; j++){
      partialsum += peoples[i-1][j];
      peoples[i][j] = partialsum;
    }
  }
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> k >> n;
    cout << peoples[k][n] << endl;
  }
  return 0;
}
