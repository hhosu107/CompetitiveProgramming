#include<bits/stdc++.h>

using namespace std;

/* A: likes aeiou(with uppercase also), B: likes others except y. */
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  string name;
  cin >> n;
  for(int t=1; t<=n; t++) {
    cin >> name;
    char x = name[name.length() - 1];
    cout << "Case #" << t << ": " << name << " is ruled by ";
    if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
      cout << "Alice.\n";
    } else if (x != 'Y' && x != 'y') {
      cout << "Bob.\n";
    } else {
      cout << "Nobody.\n";
    }
  }
  return 0;
}
