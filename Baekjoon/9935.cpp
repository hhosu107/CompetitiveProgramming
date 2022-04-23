#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string orig, bomb;
  cin >> orig >> bomb;
  stack<char> bomb_check;
  stack<char> bomb_container;
  for(int i=0; i<orig.length(); i++) {
    int j = bomb.length() - 1;
    bomb_check.push(orig[i]);
    // When bomb_candidate's length >= bomb's length, we have to check whether
    // or not it is bomb.
    if (bomb_check.top() == bomb.back() && bomb_check.size() >= bomb.length()) {
      for(; j>=0; j--) {
        if(bomb_check.top() == bomb[j]) {
          bomb_container.push(bomb_check.top());
          bomb_check.pop();
        }
        else break;
      }
      // Not a bomb
      if (j != -1) {
        while(!bomb_container.empty()) {
          bomb_check.push(bomb_container.top());
          bomb_container.pop();
        }
      }
      // bomb
      else {
        while(!bomb_container.empty()) {
          bomb_container.pop();
        }
      }
      // After this, bomb_container may be empty or not.
      // We can greedily find bombs using remaining characters in
      // bomb_container.
    }
  }
  // In this line, bomb_container might not be empty.
  string result = "";
  while(!bomb_check.empty()) {
    result += bomb_check.top();
    bomb_check.pop();
  }
  if (result.compare("") == 0) cout << "FRULA\n";
  else {
    reverse(result.begin(), result.end());
    cout << result << '\n';
  }
  return 0;
}
