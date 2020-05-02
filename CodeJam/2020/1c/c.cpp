#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/* C.
 * enourmous pancakes all of the same size.
 * Each one is too larse to serve whole, so chefs already started to chop into slices. (circular sectors)
 * Currently have N slices, the ith of which is a sector with an internal angle of A_i nanodegrees (10^-9 degrees)
 * D diners, each diner wants a single slice that is the same size as every other's slice.
 * But current slices will not be used because of differences, so make one or more radial cuts.
 * Cut X angle to Y and X - Y , where 0 < Y < X are not need to be integers.
 * It is OK to have leftover slices of any size.
 * Determine the smallest total number of cuts.
 * 1<=A_j<360*10^9,
 * set 1: 1<=N<=300, 2<=D<=3,
 * set 2: D <= 50,
 * set3:
 * N <= 10000, >= 9000 for 21 cases, <=1000 for other T - 21 cases.
 */

typedef long long int ll;
typedef struct piece{
  ll size;
  int count;
}piece;

int C1(int D, vector<ll> &cakes) {
  int len = cakes.size();
  piece c;
  c.size = cakes[0];
  c.count = 1;
  vector<piece> li = vector<piece>();
  li.push_back(c);
  vector<int> doub = vector<int>();
  vector<int> trip = vector<int>();
  for(int i=1; i<len; i++){
    int cakelen = li.size();
    bool found = false;
    for(int j=0; j<cakelen; j++){
      if (cakes[i] == li[j].size){
        li[j].count++;
        found = true;
        if (li[j].count >= 2){
          doub.push_back(j);
        }
        if (li[j].count >= 3){
          trip.push_back(j);
        }
        break;
      }
    }
    if (!found){
      c.size = cakes[i];
      c.count = 1;
      li.push_back(c);
    }
  }
  if (D == 2){
    if(doub.size() > 0){
      return 0;
    } else return 1;
  } else if (D == 3){
    if(trip.size() > 0){
      return 0;
    } else {
      for (int di: doub){
        for(int j=0; j<len; j++){
          if (j == di) continue;
          if (li[di].size < cakes[j]) {
            return 1;
          }
        } 
      }
      for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
          if (cakes[i] * 2 == cakes[j] || cakes[j] * 2 == cakes[i])
            return 1;
        }
      }
      return 2;
    }
  } else return -1;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N, D;
    cin >> N >> D;
    vector<ll> cakes = vector<ll>(N);
    for (int i=0; i<N; i++)
      cin >> cakes[i];
    int ans = C1(D, cakes);
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
