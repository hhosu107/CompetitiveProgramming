#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

/* Speed typing. Making mistakes.
 */

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int n, m;
    cin >> n >> m;
    vector<int> reg(n);
    for (int &r: reg)
      cin >> r;
    sort(reg.rbegin(), reg.rend());
    int largest_m_1 = 0;
    for(int i=0; i<m-1; i++) {
      largest_m_1 += reg[i];
    }
    largest_m_1 *= 10;
    // find median from reg[m-1] to reg[n-1].
    // What are the indices?
    // if (n - m) % 2 == 1, (n+m)/2 - 1, (n + m) / 2. Otherwise, (n+m)/2 - 1.
    int mth = (n - m) % 2 == 1 ? 5 * (reg[(n+m)/2 - 1] + reg[(n+m)/2]) : 10 * reg[(n+m)/2 - 1];
    double sum_med = (double)(largest_m_1 + mth) / 10.0;
    cout << "Case #" << t << ": " << fixed << setprecision(1) << sum_med << '\n';
  }
  return 0;
}
