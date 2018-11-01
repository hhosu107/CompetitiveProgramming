#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int main(){
  int s, e;
  cin >> s >> e;
  vector<pair<bool, int>> visited(100001, pair<bool, int>(false, -1));
  queue<pair<int, pair<int, int> > > q;
  q.push(pair<int, pair<int, int> >(s, pair<int, int>(0, -1)));
  visited[s].first = true;
  while((q.front()).first != e){
    pair<int, pair<int, int>> curr = q.front();
    q.pop();
    if(curr.first-1 >= 0 && !visited[curr.first-1].first){
    visited[(curr.first-1)].first = true;
    visited[(curr.first-1)].second = curr.first;
      q.push(pair<int, pair<int, int>>(curr.first-1, pair<int, int>((curr.second).first + 1, curr.first)));
    }
    if(curr.first+1 <= 100000 && !visited[curr.first+1].first){
    visited[(curr.first)+1].first = true;
    visited[(curr.first)+1].second = curr.first;
      q.push(pair<int, pair<int, int>>(curr.first+1, pair<int, int>((curr.second).first + 1, curr.first)));
    }
    if(curr.first * 2 <= 100000 && !visited[curr.first * 2].first){
    visited[(curr.first) * 2].first = true;
    visited[(curr.first) * 2].second = (curr.first);
      q.push(pair<int, pair<int, int>>(curr.first * 2, pair<int, int>((curr.second).first + 1, curr.first)));
    }
  }
  int point = e;
  int time = ((q.front()).second).first;
  cout << time << endl;
  stack<int> trace;
  trace.push(e);
  while(visited[point].second != -1){
    trace.push(visited[point].second);
    point = visited[point].second;
  }
  while(!trace.empty()){
    cout << trace.top() << ' ';
    trace.pop();
  }
  cout << endl;
  return 0;
}
