#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* C: R*C floors, R*C competitors, A cutting edge automated judge for the competition, but where are audience?
 * Compute interest level.
 * Compass neighbor of x is a competitor y chosen such that y shares a row or column with x, and there are no competitors still standing in cells in between x and y. Thus each may have between 0 and 4 compass neighbors.
 * Competition runs on round at a time. Between i and i+1, if a competitor d had at least one compass neighbor during round i and d's skill is strictly less than the average skill level of all of d's compass "neighbors", d is eliminated and is not part of the competition for rounds i+1, i+2, i+3, ... Notice that d still counts as a neighbot of their other compass neighbots for the purpose of other eliminations (I.E., Each "will be eliminated" will be dicided at the same time, not the online
 * updated). Competitors without any compass neighbors are never eliminated. If after a round no competitor is eliminated, then the competition ends.
 * The interest level of a round is the sum of skill levels of the competitors dancing in that round. The interest level of the competition is the sum.
 * Compute the interest level of the competition.
 */

typedef long long int ll;
ll c1(int R, int C, vector<vector<int>> &floor) {
  vector<vector<bool>> rem = vector<vector<bool>>(R, vector<bool>(C, true));
  vector<vector<bool>> nxt = vector<vector<bool>>(R, vector<bool>(C, true));
  ll sum = 0;
  bool elim = true;
  while(elim) {
    elim = false;
    ll round = 0;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        if (!rem[i][j]){
          nxt[i][j] = false;
          continue;
        }
        round += floor[i][j];
        ll cnt = 0, sum = 0;
        for(int k=i-1; k>=0; k--){
          if(rem[k][j]){
            cnt++;
            sum += floor[k][j];
            break;
          }
        }
        for(int k=i+1; k<R; k++){
          if(rem[k][j]){
            cnt++;
            sum += floor[k][j];
            break;
          }
        }
        for(int k=j-1; k>=0; k--){
          if(rem[i][k]){
            cnt++;
            sum += floor[i][k];
            break;
          }
        }
        for(int k=j+1; k<C; k++){
          if(rem[i][k]){
            cnt++;
            sum += floor[i][k];
            break;
          }
        }
        if (floor[i][j] * cnt < sum){
          nxt[i][j] = false;
          elim = true;
        }
      }
    }
    sum += round;
    for(int i=0; i<R; i++){
      copy(nxt[i].begin(), nxt[i].end(), rem[i].begin());
    }
  }
  return sum;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, R, C;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> R >> C;
    vector<vector<int>> floor = vector<vector<int>>(R, vector<int>(C));
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cin >> floor[i][j];
      }
    }
    cout << "Case #" << t << ": " << c1(R, C, floor) << endl;
  }
  return 0;
}
