/* 1761: Given tree, find the distance of given queries of each pair of nodes. 
 * Sol) BFS.
 * Note: TLE on the Judge. Should I process "many queries in one cycle?"
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<pair<int, int>>> con;
queue<pair<pair<int, int>, int>> query; // pair: parent, current / cumulated distance
int main(){
  int N, M;
  int l, r, dist;
  int s, e;
  cin >> N;
  con = vector<vector<pair<int, int>>>(N+1, vector<pair<int, int>>());
  for(int i=0; i<N-1; i++){
    scanf("%d %d %d", &l, &r, &dist);
    con[l].push_back(pair<int, int>(r, dist));
    con[r].push_back(pair<int, int>(l, dist));
  }
  cin >> M;
  for(int i=0; i<M; i++){
    scanf("%d %d", &s, &e);
    query = queue<pair<pair<int, int>, int>>();
    query.push(pair<pair<int, int>, int>(pair<int, int>(0, s), 0));
    bool flag = false;
    while(!query.empty()){
      pair<pair<int, int>, int> curr = query.front();
      for(auto path : con[(curr.first).second]){
        if(path.first == e){
          printf("%d\n", curr.second + path.second);
          flag = true;
          break;
        }
        else if(path.first == (curr.first).first)
          continue;
        query.push(pair<pair<int, int>, int>(pair<int, int>((curr.first).second, path.first), curr.second + path.second));
      }
      if(flag) break;
      query.pop();
    }
  }
  return 0;
}
