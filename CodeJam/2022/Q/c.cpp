#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

// C. Dices.
// N dice. ith die: dS_i. 1~S_i.
// A straight of length l starting at x: x, x+1, ..., x+l-1.
// Want to choose some of dices and pick one number from each dir,
// to generate a straight.
// What is the longest straight? print maximum number of input dice
// that can be put in a straight.
// Sol) Want: x <= s'_1, ..., x+l-1 <= s'_l.
// Sol) Sort dices, let x=1, find maximum index that index <= s'_index.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(nullptr);
  int T, N;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N;
    vector<int> dices(N);
    for (auto &d: dices) cin >> d;
    sort(dices.begin(), dices.end());
    int streak = 0;
    for(int i=0; i<N; i++) {
      if (dices[i] >= streak + 1) streak++;
    }
    cout << "Case #" << t << ": " << streak << '\n';
  }
  return 0;
}
