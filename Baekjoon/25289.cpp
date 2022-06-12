#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> values(n);
  for(auto &i: values) cin >> i;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  int max_seqlen = 2;
  int curr_seqlen = 2;
  int curr_diff = values[1] - values[0];
  for(int i=2; i<n; i++) {
    if (values[i] - values[i-1] == curr_diff) {
      curr_seqlen += 1;
    } else {
      curr_diff = values[i] - values[i-1];
      max_seqlen = max(max_seqlen, curr_seqlen);
      curr_seqlen = 2;
    }
  }
  max_seqlen = max(max_seqlen, curr_seqlen);
  cout << max_seqlen << '\n';
  return 0;
}
