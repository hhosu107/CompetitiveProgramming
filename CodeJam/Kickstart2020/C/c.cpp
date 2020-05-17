#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include<cmath>
using namespace std;
typedef long long ll;
/* C. N ints: A_i as ith value. Possibly negative.
 * A contiguos non empty subarray is perfect if its total sum is a perfect square.
 * How many subarrays are perfect?
 * Problem: some of the subproblem may require n log n solution. But small version doesn't require.
 */
typedef long double ld;
bool isPerfect(ld x){
  if (x < 0) return false;
  ld sr = sqrt(x);
  return ((sr - floor(sr)) < 0.00001 || (ceil(sr) - sr) < 0.00001);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    int N;
    cin >> N;
    vector<ld> subsum = vector<ld>(N + 1);
    int cnt = 0;
    for(int i=0; i<N; i++){
      ld y;
      cin >> y;
      if(i == 0) subsum[1] = y;
      else{
        subsum[i+1] = subsum[i] + y;
      }
      for(int j=0; j<i+1; j++){
        bool sqr = isPerfect(subsum[i+1] - subsum[j]);
        if(sqr) cnt++;
      }
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
  return 0;
}
