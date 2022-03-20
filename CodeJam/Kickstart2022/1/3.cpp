#include<bits/stdc++.h>

using namespace std;

bool q_fill_no_palindrome(string s, vector<int> &q, vector<int> filler, int n) {
  if (q.size() == n) {
    string x = s;
    for(int i=0; i<n; i++) {
      x[q[i]] = (char)(filler[i] + '0');
    }
    int max_len = s.size() * 2 - 1;
    for(int st = 4; st < max_len - 4; st++) {
      bool non_palindrome = false;
      for(int delta = 0; delta <= 4; delta += 2) {
        int real_delta = (st % 2 == 0 ? delta : delta + 1);
        if (x[(st - real_delta) / 2] != x[(st + real_delta) / 2]) {
          non_palindrome = true;
          break;
        }
      }
      if (!non_palindrome) {
        return false;
      }
    }
    return true;
  }
  else {
    bool flag = q_fill_no_palindrome(s, q, filler, n + 1);
    if (flag) return true;
    filler[n] = 1;
    flag = q_fill_no_palindrome(s, q, filler, n + 1);
    return flag;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T, n;
  string q;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    cin >> q;
    vector<int> q_loc = vector<int>();
    for(int i=0; i<n; i++) {
      if(q[i] == '?') {
        q_loc.push_back(i);
      }
    }
    vector<int> filler = vector<int>(q_loc.size(), 0);
    bool possible = q_fill_no_palindrome(q, q_loc, filler, 0);
    cout << "Case #" << t << ": " << (possible ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }
  return 0;
}
