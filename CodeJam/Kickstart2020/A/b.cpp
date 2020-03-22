#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B.
 * N stacks of plates / each stack with K plates
 * Each plate with positive beauty value
 * Take exactly P plates - for each stack, take from above to rear (not the intermediate one)
 * Maximize the total sum of beauty values.
 * Sol)
 * For each stack, compute the sub-sum
 * and pick the most valuable sub-sum (within the remaining number of plates) and recalculate the subsum.
 */
int T, N, K, P;
int b[50][30];
int p_idx[50];
int b_sub[50][31]; // b_sub[i][j+1] = sum_k<=j b[i][k]
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> K >> P;
    for(int i=0; i<N; i++){
      for(int j=0; j<K; j++){
        cin >> b[i][j];
        b_sub[i][j+1] = b_sub[i][j] + b[i][j];
      }
      p_idx[i] = 0;
    }
    int max_b = 0;
    while (P > 0){
      int max_val = 0, max_stack = -1, max_len = 1;
      for(int i=0; i<N; i++){
        int left_len = (P < K - p_idx[i] ? p_idx[i] + P : K);
        for(int j=p_idx[i]; j<left_len; j++){
          if (b_sub[i][j+1] * max_len > max_val * (j - p_idx[i] + 1)) {
            max_val = b_sub[i][j+1];
            max_stack = i;
            max_len = j - p_idx[i] + 1;
          }
        }
      }
      P -= max_len;
      max_b += b_sub[max_stack][p_idx[max_stack] + max_len];
      for(int j=p_idx[max_stack] + max_len + 1; j<=K; j++){
        b_sub[max_stack][j] -= b_sub[max_stack][p_idx[max_stack] + max_len];
      }
      p_idx[max_stack] += max_len;
    }
    cout << "Case #" <<  t << ": " << max_b << endl;
  }
  return 0;
}
