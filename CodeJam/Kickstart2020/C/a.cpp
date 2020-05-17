#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  int N, K;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> K;
    vector<ll> val = vector<ll>(N);
    int cnt = 0;
    int curr_cd = K + 1;
    int idx = -1;
    for(int i=0; i<N; i++){
      cin >> val[i];
      if (val[i] + 1 == curr_cd){
        curr_cd -= 1;
        if (curr_cd == 1){
          cnt++;
          curr_cd = K + 1;
        }
      } else {
        if (val[i] == K){
          curr_cd = K;
        }
        else {
          curr_cd = K + 1;
        }
      }
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
  return 0;
}
