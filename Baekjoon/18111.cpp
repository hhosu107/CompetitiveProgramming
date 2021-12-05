#include<iostream>
#include<vector>

using namespace std;

int main () {
  int n, m, b;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> b;
  vector<int> blks = vector<int>(n*m);
  int maxh = 0;
  for(auto& blk: blks){
    cin >> blk;
    if (blk > maxh) maxh = blk;
  }
  int mincost = n * m * maxh * 2;
  int h = 0;
  for(int i=maxh; i>=0; i--){
    int cost = 0;
    int moreb = 0;
    int needb = 0;
    for(auto blk: blks){
      if (blk < i) {
        cost += (i - blk);
        needb += (i - blk);
      }
      else {
        cost += 2 * (blk - i);
        moreb += (blk - i);
      }
    }
    if (moreb + b < needb) continue;
    else if (cost < mincost) {
      mincost = cost;
      h = i;
    }
  }
  cout << mincost << ' ' << h << '\n';
  return 0;
}
