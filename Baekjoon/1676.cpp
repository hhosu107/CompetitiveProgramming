#include<iostream>
using namespace std;
int main () {
  int n;
  int fivecnt = 0;
  cin >> n;
  for(int i=5; i<=n; i+=5) {
    int x = i;
    while(x % 5 == 0) {
      fivecnt++;
      x /= 5;
    }
  }
  cout << fivecnt << endl;
  return 0;
}
