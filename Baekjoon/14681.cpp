#include<iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans;
  if (b > 0) ans = 1 + (a > 0 ? 0 : 1);
  else ans = 5 - (a > 0 ? 1 : 2);
  cout << ans << endl;
  return 0;
}
