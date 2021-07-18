#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

pii count_papers(vector<vector<int>> &color, int leftx, int lefty, int length){
  if (length == 1){
    return pii(1 - color[leftx][lefty], color[leftx][lefty]);
  }
  else {
    vector<pii> four_side = vector<pii>(4);
    four_side[0] = count_papers(color, leftx, lefty, length / 2);
    four_side[1] = count_papers(color, leftx + (length / 2), lefty, length / 2);
    four_side[2] = count_papers(color, leftx, lefty + (length / 2), length / 2);
    four_side[3] = count_papers(color, leftx + length / 2, lefty + length / 2, length / 2);
    pii merged = pii(0, 0);
    for(int i=0; i<4; i++){
      merged.first += four_side[i].first;
      merged.second += four_side[i].second;
    }
    if (merged.first == 4 && merged.second == 0){
      return pii(1, 0);
    } else if (merged.second == 4 && merged.first == 0){
      return pii(0, 1);
    } return merged;
  }
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> color = vector<vector<int>>(N, vector<int>(N, 0));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      cin >> color[i][j];
  }
  pii result = count_papers(color, 0, 0, N);
  cout << result.first << '\n' << result.second << '\n';
  return 0;
}
