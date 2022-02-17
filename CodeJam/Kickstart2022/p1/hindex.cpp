#include<bits/stdc++.h>

using namespace std;

/* H index: the largest H that researcher has H papers with at least H citations each */
/* Determine H score after each paper he wrote. */
/* Sol) Make minheap.
 * We control the H: H index. When a new one comes, first judge that one
 * is larger than current H. If not, don't care. If it does, first put that into
 * the minheap. And then, if the smallest one of the minheap is larger than H,
 * we can finally increase H by 1. If not, pop it out.
 * By this strategy, we can maintain the size of the minheap as H always. */
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> hscore(n, 0);
    int H = 0;
    int x;
    for(int i=0; i<n; i++) {
      cin >> x;
      if(minheap.empty()) {
        minheap.push(x);
        H = 1;
      } else if (x > H) {
        minheap.push(x);
        if (minheap.top() > H) {
          H++;
        } else {
          minheap.pop();
        }
      }
      hscore[i] = H;
    }
    cout << "Case #" << t << ": ";
    for(auto h: hscore) {
      cout << h << " ";
    }
    cout << '\n';
  }
  return 0;
}
