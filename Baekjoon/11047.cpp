#include<iostream>
#include<vector>

using namespace std;

/* 11047. Coin: Since the next coin is a multiple of the right before coin, greedy. */
int main(){
  int n, k, a[10];
  cin >> n >> k;
  for(int i=0; i<n; i++)
    cin >> a[i];
  int cnt = 0;
  int kk = k;
  int coin_idx = n - 1;
  while(kk > 0){
    int kk_div = kk / a[coin_idx];
    int kk_rem = kk - kk_div * a[coin_idx];
    cnt += kk / a[coin_idx];
    kk = kk_rem;
    coin_idx--;
  }
  cout << cnt << endl;
  return 0;
}
