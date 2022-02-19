#include<iostream>
#include<set>

using namespace std;


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T-- > 0) {
    int n;
    cin >> n;
    multiset<int> s = multiset<int>();
    char op; int x;
    for(int i=0; i<n; i++){
      cin >> op >> x;
      if (op == 'I') {
        s.insert(x);
      } else {
        if (s.size() == 0) continue;
        if (x == -1) {
          s.erase(s.begin());
        } else {
          auto it = s.end();
          it--;
          s.erase(it);
        }
      }
    }
    if (s.empty()) cout << "EMPTY\n";
    else {
      cout << *s.rbegin() << " " << *s.begin() << '\n';
    }
  }
  return 0;
}
