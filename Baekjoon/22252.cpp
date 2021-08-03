#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  map<string, priority_queue<int>> gorilas = map<string, priority_queue<int>>();
  int n;
  long long int infosum = 0;
  string gorila;
  int q, b, k;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> q >> gorila;
    if (q == 1){
      cin >> k;
      auto it = gorilas.find(gorila);
      if (it == gorilas.end()){
        priority_queue<int> new_info = priority_queue<int>();
        for(int i=0; i<k; i++){
          cin >> b;
          new_info.push(b);
        }
        gorilas.insert(make_pair(gorila, new_info));
      } else {
        for(int i=0; i<k; i++){
          cin >> b;
          gorilas[gorila].push(b);
        }
      }
    }
    else {
      cin >> b;
      for(int j=0; j<b; j++){
        if (gorilas[gorila].empty()) break;
        else {
          int top = gorilas[gorila].top();
          gorilas[gorila].pop();
          infosum += top;
        }
      }
    }
  }
  cout << infosum << '\n';

  return 0;
}
