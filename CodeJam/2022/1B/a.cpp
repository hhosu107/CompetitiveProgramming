#include<bits/stdc++.h>
using namespace std;

int main () {
  int T, N;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> N;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    int left_idx = 0, right_idx = N-1;
    int curr_score = -1;
    int curr_approved = 0;
    while(left_idx <= right_idx) {
      int selected_idx = min(A[left_idx], A[right_idx]) == A[left_idx] ? left_idx : right_idx;
      if (selected_idx == left_idx) {
        left_idx++;
      } else {
        right_idx--;
      }
      if (curr_score <= A[selected_idx]) {
        curr_approved++;
        curr_score = A[selected_idx];
      }
    }
    cout << "Case #" << t << ": " << curr_approved << '\n';
  }
  return 0;
}
