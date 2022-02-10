#include<string>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main () {
  int n, m;
  cin >> n >> m;
  set<string> a, b;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    a.insert(s);
  }
  for(int i=0; i<m; i++){
    string s;
    cin >> s;
    b.insert(s);
  }
  set<string> ab;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(ab, ab.begin()));
  cout << ab.size() << '\n';
  for(auto i: ab)
    cout << i << '\n';
  return 0;
}
