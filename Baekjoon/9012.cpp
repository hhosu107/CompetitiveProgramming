#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
  string s;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> s;
    stack<char> par;
    bool balanced = true;
    for(char c: s) {
      if (c == ')'){
        if (par.empty()) {
          balanced = false;
          break;
        }
        char top = par.top();
        if (top != '(') {
          balanced = false;
          break;
        } else {
          par.pop();
        }
      } else if (c == '('){
        par.push(c);
      }
    }
    if (!balanced || !par.empty()) {
      cout << "NO\n";
    } else cout << "YES\n";
  }
  return 0;
}
