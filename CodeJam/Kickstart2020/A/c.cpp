#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

typedef struct diffseg {
  long long int d;
  long long int segcnt;
} diffseg;

bool operator<(diffseg t, diffseg u){
  return t.d * u.segcnt > t.segcnt * u.d;
}

/* C. Workout
 * N sessions, M_i minutes to take (M_i < M_i+1 for every i)
 * difficulty = max_i (m_i+1 - m_i)
 * To decrease difficulty, add up to K additional training sessions, while maintaining strictly increasing training time.
 * Find the minimum difficulty.
 * ex) 5,6 : 9 10 20 26 30: answer = 3 (13, 16, 18, 22, 24, 28)
 * sol) Maintain a heap with <diff, segment_num> where comparator compares diff_a * segnum_b and diff_b * segnum_a, and the root of the heap has the maximum value of diff / segment_num
 */
// Try small
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N, K;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> K;
    priority_queue<diffseg> pq;
    vector<int> M = vector<int>(N, 0);
    vector<int> d = vector<int>(N-1, 0);
    cin >> M[0];
    int mdiff_idx = -1, mdiff = -1;
    for(int i=1; i<N; i++){
      cin >> M[i];
      d[i-1] = M[i] - M[i-1];
      if(mdiff < d[i-1]){
        mdiff_idx = i-1;
        mdiff = d[i-1];
      }
    }
    mdiff = d[mdiff_idx] = (d[mdiff_idx] + 1) / 2;
    for(int i=0; i<N-1; i++){
      if(mdiff < d[i]){
        mdiff = d[i];
      }
    }
    cout << "Case #" << t << ": " << mdiff << endl;
  }
  return 0;
}
