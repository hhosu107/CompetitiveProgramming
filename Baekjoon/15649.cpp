#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int>> perms(vector<int> curr, int len, int m, int n){
  if (len == m) {
    return vector<vector<int>>(1, curr);
  } else {
    vector<vector<int>> result = vector<vector<int>>(0, vector<int>());
    int leftcap = (len == 0 ? 0 : curr[len - 1]);
    for(int next = 1; next <= n; next++){
      vector<int> nextcurr (curr);
      bool keep = true;
      for(int i=0; i<len; i++){
        if (curr[i] == next) { keep = false; break;}
      }
      if(!keep) continue;
      nextcurr.push_back(next);
      vector<vector<int>> curr_result = perms(nextcurr, len + 1, m, n);
      result.insert(result.end(), curr_result.begin(), curr_result.end());
    }
    return result;
  }
}

int main(){
  int N, M;
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  vector<vector<int>> result = perms(vector<int>(), 0, M, N);
  for(vector<int> line : result){
    for(int elmt : line){
      cout << elmt << " ";
    }
    cout << '\n';
  }
  return 0;
}
