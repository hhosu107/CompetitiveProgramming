/* 11066.
 * C1, .., Cn. We will merge two files into one file, and repeat it until there is only one file.
 * Minimal cost to merge? (cost: if we merge ci, cj to make a new file f, the cost is ci+cj)
 * sol) Compute every cost to merge C_i, ..., C_j, and finally get cost(1..K).
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int _INT_MAX = 2147483647;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  int T, K;
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> K;
    vector<int> pages = vector<int>(K);
    vector<int> partial_sum = vector<int>(K + 1);
    for(int i=0; i<K; i++){
      cin >> pages[i];
      partial_sum[i+1] = partial_sum[i] + pages[i];
    }
    vector<vector<int>> ijmerge = vector<vector<int>>(K + 1, vector<int>(K + 1));
    for(int dist = 1; dist < K; dist++){
      for(int i = 1; i + dist <= K; i++){
        int j = i + dist;
        ijmerge[i][j] = _INT_MAX;
        for(int mid = i; mid < j; mid++){
          ijmerge[i][j] = min(ijmerge[i][j], ijmerge[i][mid] + ijmerge[mid+1][j] + partial_sum[j] - partial_sum[i-1]);
        }
      }
    }
    cout << ijmerge[1][K] << '\n';
  }
  return 0;
}
