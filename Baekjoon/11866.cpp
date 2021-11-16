#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  int k, n;
  queue<int> joseph;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  cout << "<";
  for(int i=1; i<=n; i++)
    joseph.push(i);
  int kth = 0;
  while(!joseph.empty()){
    int top = joseph.front();
    kth++;
    joseph.pop();
    if (kth == k) {
      kth = 0;
      cout << top;
      if(!joseph.empty()){
        cout << ", ";
      }
    } else {
      joseph.push(top);
    }
  }
  cout << ">\n";
  return 0;
}
