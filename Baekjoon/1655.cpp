#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int dp[101][100001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  priority_queue<int> smaller = priority_queue<int>();
  priority_queue<int, vector<int>, greater<int>> larger = priority_queue<int, vector<int>, greater<int>>();
  int n;
  cin >> n;
  int num;
  for(int i=0; i<n; i++){
    cin >> num;
    if (smaller.size() > larger.size()) {
      larger.push(num);
    } else smaller.push(num);
    if (i >= 1){
      if(larger.top() < smaller.top()){
        int ltop = larger.top();
        larger.pop();
        int stop = smaller.top();
        smaller.pop();
        larger.push(stop);
        smaller.push(ltop);
      }
    }
    cout << smaller.top() << '\n';
  }
  return 0;
}
