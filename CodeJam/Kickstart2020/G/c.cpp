#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 1; t<=T; t++){
    int W, N;
    cin >> W >> N;
    vector<int> vals = vector<int>(W, 0);
    ll ans = (ll)1<<62;
    for(int i=0; i<W; i++){
      cin >> vals[i];
    }
    for(int i=0; i<W; i++){
      ll tmp = 0;
      int val = vals[i];
      for(int j=0; j<W; j++){
        int dif = val - vals[j];
        if (dif < 0) dif = -dif;
        dif = (dif > N - dif ? N - dif : dif);
        tmp += dif;
      }
      if (ans > tmp) ans = tmp;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
