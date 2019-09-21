#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int p10s[10];
long long int base[9];
long long int prec[9];
int main() {
  long long int p10 = 10;
  base[0] = 0;
  p10s[0] = 1;
  prec[0] = 45;
  for(int i=1; i<9; i++, p10*=10){
    p10s[i] = p10;
    base[i] = base[i-1] + (p10 - (p10/10)) * i;
    prec[i] = base[i] * 9 * p10 + (i + 1) * (9 * p10) * (9 * p10 + 1) / 2;
  }
  p10s[9] = p10;
  int n;
  long long int q;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> q;
    int border = 0;
    long long int curr = 0;
    long long int c10 = 1;
    while(1){
      if(curr + prec[border] >= q){
        break;
      }
      curr += prec[border];
      border++;
      c10 *= 10;
    }
    int borderI = c10;
    while(1){
      if(curr + base[border] + (border + 1) * (borderI - c10 + 1) >= q){
        break;
      }
      curr += base[border] + (border + 1) * (borderI - c10 + 1);
      borderI++;
    }
    int numIdx = 0;
    int num = 1;
    while(1){
      if(curr + numIdx + 1 >= q) break;
      curr += numIdx + 1;
      num++;
      if(num == p10s[numIdx+1]){numIdx++;}
    }
    int digitIdx = curr + numIdx + 1 - q;
    int digit;
    while(digitIdx>=0){
      digit = num % 10;
      num /= 10;
      digitIdx--;
    }
    printf("%d\n", digit);
  }
  return 0;
}
