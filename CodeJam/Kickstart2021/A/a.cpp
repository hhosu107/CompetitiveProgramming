#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

// goodness score of a string as the number of indices i such that S_i != S_(n+1)-i where 1 <= i <= N/2 (1-indexed).
// Given a string of length N, convert to a string with a goodness score of K.
// Then compute the minimum number of operations.
// Sol: compute the original score, and find difference between the target. That is the answer.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  string ss;
  int T, K, N;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N >> K;
    cin >> ss;
    int score = 0;
    for (int i=0; i<(N/2); i++){
      if (ss[i] != ss[N-1-i]) score++;
    }
    int target = (score - K < 0 ? K - score : score - K);
    cout << "Case #" << t << ": " << target << endl;
  }
  return 0;
}
