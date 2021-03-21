#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

/*
 * B. N shards, arrange from 1 to N
 * 2. Note: Color C_i = either "A" or "B"
 * 3. Choose a consecutive sequence of three shards, remove, fuse into one shard (select i-1/i/i+1 and fuse.)
 * 3.1 At least one shard must have the different color; or such an intense concentration of similar energies will cause a dangeroud rebound explosion.
 * Thus, the dominating color of shard will be the color of the fused shard.
 * 4. Place the resulting shard back into the original gap in the row; i.e., relative order of shards remains.
 * 5. Repeat 3/4 until only one remains. (Trivially, the initial shards are odd.)
 * Sol) ||A|-|B|| = 1. Otherwise it explodes.
 * Can we prove that if ||A|-|B|| == 1 => Doesn't explode?
 * Let's start from AAA....ABB...B where |A| - |B| = 1.
 * Can we rearrange this to generate any combination of A and B without explosion?
 */
using namespace std;
int main(){
  int T, n;
  string shards;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    cin >> shards;
    int ac = 0, bc = 0;
    for(char x: shards){
      if (x == 'A') ac++;
      else if (x == 'B') bc++;
    }
    cout << "Case #" << t << ": " << ((ac - bc == 1 || ac - bc == -1) ? "Y\n" : "N\n");
  }
  return 0;
}
