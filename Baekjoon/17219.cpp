#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main () {
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> sp;
  for(int i=0; i<n; i++) {
    string s, p;
    cin >> s >> p;
    sp[s] = p;
  }
  for(int i=0; i<m; i++) {
    string s;
    cin >> s;
    cout << sp[s] << '\n';
  }
  return 0;
}

