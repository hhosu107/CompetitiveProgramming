/* Computing Largest Prime Factor */
#include<cstdio>
#include<iostream>
using namespace std;
long long int f;
int main(){
  cin >> f;
  long long int d = 3;
  while(d * d <= f){
    if(f % d == 0){
      f /= d;
    }
    else d += 2;
  }
  cout << f << endl;
  return 0;
}
