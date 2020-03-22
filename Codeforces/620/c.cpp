#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int q;
  cin >> q;
  for (int i=0; i<q; i++){
    int n, m;
    cin >> n >> m;
    int prev_t = 0, prev_l = m, prev_h = m;
    int t, l, h;
    bool possible = true;
    for (int j=0; j<n; j++){
      cin >> t >> l >> h;
      if(!possible) continue;
      int dt = t - prev_t;
      int pos_l = prev_l - dt;
      int pos_h = prev_h + dt;
      if (pos_h < l || pos_l > h){
        possible = false;
      } else {
        prev_t = t;
        prev_l = pos_l < l ? l : pos_l;
        prev_h = pos_h > h ? h : pos_h;
      }
    }
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
