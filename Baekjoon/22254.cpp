#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

bool kpossible(int k, vector<int> &presents, int X) {
  priority_queue<int, vector<int>, greater<int>> processors = priority_queue<int, vector<int>, greater<int>>();
  for(int i=0; i<k; i++)
    processors.push(0);
  for(int present: presents){
    int top = processors.top();
    processors.pop();
    if (top + present > X)
      return false;
    processors.push(top + present);
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int n, X;
  cin >> n >> X;
  vector<int> presents = vector<int>(n);
  for(int i=0; i<n; i++)
    cin >> presents[i];
  int left = 1, right = n;
  int minK = n + 1;
  while(left < right){
    int mid = (left + right) / 2;
    if (kpossible(mid, presents, X)){
      right = mid - 1;
      if (mid < minK)
        minK = mid;
    } else {
      left = mid + 1;
    }
  }
  if (kpossible(left, presents, X)) {
    if (minK > left){
      minK = left;
    }
  }
  cout << minK << '\n';
  return 0;
}
