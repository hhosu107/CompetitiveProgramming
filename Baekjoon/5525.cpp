#include<iostream>
#include<string>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ans = 0;
  int start = 0, end = 0;
  while(end < m) {
    if(s[end] == 'I') {
      start = end;
      bool pattern = true;
      if (end + 2 * n > m - 1) {
        end = m;
        continue;
      }
      for (int i = end + 1; i <= end + 2 * n; i++) {
        if(((i - end) % 2 == 1 && s[i] == 'I') || ((i - end) % 2 == 0 && s[i] == 'O')) {
          if ((i - end) % 2 == 1) {
            start = i;
            end = i;
            pattern = false;
            break;
          }
          else {
            pattern = false;
            end = i + 1;
            break;
          }
        }
      }
      if (pattern) {
        ans++;
        for(int i = end + 2 * n + 1; i <= m - 1; i++) {
          if((i - end) % 2 == 1 && s[i] == 'I') {
            start = i;
            end = i;
            pattern = false;
            break;
          }
          if((i - end) % 2 == 0 && s[i] == 'O') {
            end = i + 1;
            pattern = false;
            break;
          }
          else if ((i - end) % 2 == 0) {
            ans++;
          }
        }
        if (pattern) { // i == m
          end = m;
        }
      }
    } else { // s[end] == 'O' continuously
      end++;
    }
  }
  cout << ans << endl;
  return 0;
}
