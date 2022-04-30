#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int main () {
  int T;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  for(int t=1; t<=T; t++) {
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &x: s) cin >> x;
    bool found = false;
    cout << "Case #" << t << ": ";
    bool internal_mixed = false;
    for(int i=0; i<n; i++) {
      vector<bool> used(26, 0);
      char curr_c = s[i][0];
      used[(int)(curr_c - 'A')] = true;
      for(int j=1; j<s[i].length(); j++) {
        if(s[i][j] != curr_c) {
          if(used[(int)(s[i][j] - 'A')]) {
            internal_mixed = true;
            break;
          }
          used[(int)(s[i][j] - 'A')] = true;
          curr_c = s[i][j];
        }
      }
      if (internal_mixed) {
        cout << "IMPOSSIBLE\n";
        break;
      }
    }
    if (internal_mixed) continue;
    vector<vector<int>> shelled(26, vector<int>());
    for(int i=0; i<n; i++) {
      vector<bool> used(26, 0);
      char curr_c = s[i][0];
      for(int j=1; j<s[i].length(); j++) {
        if(s[i][j] != curr_c) {
          if (used[(int)(curr_c - 'A')]) {
            shelled[(int)(curr_c - 'A')].push_back(i);
          }
          used[(int)(s[i][j] - 'A')] = true;
          curr_c = s[i][j];
        }
      }
    }
    for(int i=0; i<26; i++) {
      if (shelled[i].size() > 1) {
        internal_mixed = true;
        cout << "IMPOSSIBLE\n";
        break;
      }
    }
    if (internal_mixed) continue;
    vector<set<int>> both_end(26, set<int>() );
    vector<set<int>> left_end(26, set<int>());
    vector<set<int>> right_end(26, set<int>());
    for(int i=0; i<n; i++) {
      if (s[i][0] == s[i][s[i].length() - 1]) {
        both_end[(int)(s[i][0] - 'A')].insert(i);
      } else {
        left_end[(int)(s[i][0] - 'A')].insert(i);
        right_end[(int)(s[i][s[i].length() - 1] - 'A')].insert(i);
      }
    }
    vector<string> unc(0);
    vector<bool> used(n, false);
    for(int i=0; i<26; i++) {
      string part = "";
      for(int x: both_end[i]) {
        part += s[x];
        used[x] = true;
      }
      if (left_end[i].size() > 1 || right_end[i].size() > 1) {
        internal_mixed = true;
        break;
      }
      if (left_end[i].size() == 1) {
        int x = *left_end[i].begin();
        if (used[x]) {
          internal_mixed = true;
          break;
        } else {
          part += s[x];
          used[x] = true;
        }
      }
      left_end[i] = set<int>();
      if (right_end[i].size() == 1) {
        int x = *right_end[i].begin();
        if(used[x]) {
          internal_mixed = true;
          break;
        } else {
          part = s[x] + part;
          used[x] = true;
        }
      }
      right_end[i] = set<int>();
    }
    if (internal_mixed) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    internal_mixed = false;
    vector<bool> inserted(n, false);
    string result = "";
    for(int i=0; i<n; i++) {
      if (inserted[i]) continue;
      char start_c = s[i][0];
      char end_c = s[i][1];
      if (s[i][0] == s[i][1]) {
        char endp = start_c;
        vector<string> pool(0);
        pool.push_back(s[i]);
        for(int j=i+1; j<n; j++) {
          if (s[j][0] == s[j][1] && s[j][0] == endp) {
            pool.push_back(s[j]);
            inserted[j] = true;
          }
        } for(int j=i+1; j<n; j++) {
          if (s[j][0] == endp) {
            for(int k=j+1; k<n; k++) {
              if (s[k][0] == endp) { // violation
                internal_mixed = true;
                break;
              }
            }
          }
        }
      }
    }
    do{
      string conc = "";
      for(auto x : s) conc += x;
      vector<bool> used(26, 0);
      char curr_c = conc[0];
      used[(int)(curr_c - 'A')] = true;
      bool mixed = false;
      for(int i=1; i<conc.length(); i++) {
        if (conc[i] != curr_c) {
          if (used[(int)(conc[i] - 'A')]) {
            mixed = true;
            break;
          }
          curr_c = conc[i];
          used[(int)(conc[i] - 'A')] = true;
        }
        else {
          used[(int)(conc[i] - 'A')] = true;
        }
      }
      if (!mixed) {
        found = true;
        cout << conc << '\n';
        break;
      }
    }while(next_permutation(s.begin(), s.end()));
    if (!found) {
      cout << "IMPOSSIBLE" << '\n';
    }
  }
  return 0;
}
