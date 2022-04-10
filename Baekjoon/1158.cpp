#include<bits/stdc++.h>
using namespace std;

int main () {
  int n, k;
  int cnt = 0;
  cin >> n >> k;
  queue<int> q;
  for(int i=1; i<=n; i++)
    q.push(i);
  cout << '<';
  while(!q.empty()) {
    int c = q.front();
    q.pop();
    cnt++;
    if (cnt == k) {
      cout << c;
      cnt = 0;
      if (q.size() == 0) {
        cout << '>';
        break;
      } else cout << ", ";
    } else {
      q.push(c);
    }
  }
  cout << endl;
  return 0;
}
