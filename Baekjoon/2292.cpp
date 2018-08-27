#include<bits/stdc++.h>
using namespace std;

int main(){
  int K;
  cin >> K;
  int ans = (int)(sqrt(((double)(K)-1.25f)/3.0f)+0.5)+1;
  cout << ans << endl;
  return 0;
}
