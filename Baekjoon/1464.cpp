#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main () {
  string s;
  cin >> s;
  int n = s.size();
  deque<char> dq;
  dq.push_back(s[0]);
  for (int i=1; i<n; i++) {
    if (dq.front() >= s[i]) {
      dq.push_front(s[i]);
    } else {
      dq.push_back(s[i]);
    }
  }
  while(!dq.empty()) {
    cout << dq.front();
    dq.pop_front();
  }
  cout << endl;
  return 0;
}
