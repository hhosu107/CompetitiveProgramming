#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int t, a, b, c, d;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> a >> b >> c >> d;
    if ((b-a) % (c+d) == 0){
      cout << (b-a)/(c+d) << endl;
    } else cout << -1 << endl;
  }
  return 0;
}
