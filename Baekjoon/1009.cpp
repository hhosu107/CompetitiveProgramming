#include<cstdio>
#include<iostream>
using namespace std;

/* Problem 1009: Fermat's minor Theorem divided by 10 */

int main(){
  int N, a, b;
  int a2, a5, b5;
  int d2, d5;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a >> b;
    a2 = a%2; a5 = a%5; b5 = b%4;
    if (a2 == 0) d2 = 0;
    else d2 = 1;
    if(a5 == 0) d5 = 0;
    else d5 = 1;
    for(int j=0; j<b5; j++){
      d5 = (d5 * a5) % 5;
    }
    while(d2 != d5){
      if(d2 < d5) d2 += 2;
      else if(d2 > d5) d5 += 5;
    }
    cout << (d2 == 0 ? 10 : d2) << endl;
  }
  return 0;
}
