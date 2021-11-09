#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int parts[9] = {0};
  while(n > 0) {
    int rem = n % 10;
    if (rem == 6 || rem == 9) parts[6]++;
    else parts[rem]++;
    n /= 10;
  }
  int max = 0;
  parts[6] = (parts[6] + 1) / 2;
  for(int i=0; i<9; i++) {
    if (max < parts[i]) max = parts[i];
  }
  cout << max << endl;
  return 0;
}
