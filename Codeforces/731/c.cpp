#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

/* C. N+M minutes. Exactly one of them make one change per minute. k lines were there.
 * Actions: add a new line to the end or change one of the lines.
 * [a1, .., an]. a1 == 0: newline; a1 > 0: change a line. vice versa for [b1, .., bm]
 * Merge them into one common sequence such that this 'seems' to be correct still.
 * If impossible, print -1.
 * Sol) Suppose a1...ai and b1...bj have been done with m 0s. Then there are k + m lines.
 * If all of a_i+1 and bj+1 exceeds k+m, it is invalid.
 * Sol) What number should we select? Since 0 strictly increases the value, we should pick 0 first among current points. This greedy tactics works.
 */
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n, m, k;
    cin >> t;
    for(int T=0; T<t; T++){
      cin >> k >> n >> m;
      vector<int> a = vector<int>(n, 0);
      vector<int> b = vector<int>(m, 0);
      vector<int> merged = vector<int>(n+m, 0);
      int ha = 0, hb = 0;
      int added = 0;
      bool flag = true;
      for(int i=0; i<n; i++){
        cin >> a[i];
      }
      for(int i=0; i<m; i++){
        cin >> b[i];
      }
      for(int i=0; i<n+m; i++){
        if(ha < n && a[ha] == 0) {
          ha++;
          added++;
        } else if (hb < m && b[hb] == 0){
          hb++;
          added++;
        } else {
          if (ha < n && (hb == m || a[ha] <= b[hb])){
            if (a[ha] <= k + added){
              merged[i] = a[ha];
              ha++;
            } else {
              flag = false;
              break;
            }
          } else {
            if (b[hb] <= k + added){
              merged[i] = b[hb];
              hb++;
            } else {
              flag = false;
              break;
            }
          }
        }
      }
      if (!flag) cout << "-1" << endl;
      else {
        for(auto m : merged){
          cout << m << " ";
        }
        cout << endl;
      }
    }
    return 0;
}
