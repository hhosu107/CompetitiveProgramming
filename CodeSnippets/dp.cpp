#include<iostream>
#include<vector>
#include<algorithm> // min, max, ...
using namespace std;

/* calculate x with coins, min number of coins
 * values(x) = min (c in coins) values(x-c)+1.
 */

int values(int x, vector<int>& coins){
  vector<int> val = vector<int>(x + 1, 0);
  for(int i = 1;  i <= x; i++){
    val[i] = 999999999;
    for(auto c : coins) {
      if (i - c >= 0){
        val[i] = min(val[i], val[i - c] + 1);
      }
    }
  }
  return val[x];
}

int main(){
  return 0;
}
