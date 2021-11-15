#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
  string s;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  getline(cin, s);
  while(s.compare(".") != 0) {
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
      } else if (c == ']') {
        if (par.empty()) {
          balanced = false;
          break;
        }
        char top = par.top();
        if (top != '[') {
          balanced = false;
          break;
        } else {
          par.pop();
        }
      } else if (c == '(' || c == '['){
        par.push(c);
      }
    }
    if (!balanced || !par.empty()) {
      cout << "no\n";
    } else cout << "yes\n";
    getline(cin, s);
  }
  return 0;
}
