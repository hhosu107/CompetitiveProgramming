#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// Idea: have to record the longest path.

bool visited[2000];
int main(){
  vector<vector<int>> friends;
  int N, M;
  cin >> N >> M;
  friends = vector<vector<int>>(N, vector<int>());
  int f, s;
  for(int i=0; i<M; i++){
    cin >> f >> s;
    friends[f].push_back(s);
    friends[s].push_back(f);
  }
  queue<pair<int, int>> q;
  int exists = 0;
  for(int i=0; i<N; i++){
    if(visited[i]) continue;
    visited[i] = true;
    q.push(pair<int, int>(i, 0));
    while(!q.empty()){
      pair<int, int> curr = q.front();
      if(curr.second == 4){
        exists = 1;
        break;
      }
      q.pop();
      for(auto fr : friends[curr.first]){
        if(visited[fr] == false){
          visited[fr] = true;
          q.push(pair<int, int>(fr, curr.second+1));
        }
      }
    }
    if(exists == 1) break;
  }
  cout << exists << '\n';
  return 0;
}
