#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* C. Final exam
 * N sets of problems; each set has difficulty parameter a_i, b_i, which means
 * there are (b_i - a_i + 1) problems with difficulties a_i, a_i+1, ..., b_i.
 * Among all problems from all sets, no two problems have the same difficulty.
 * Tester tests M students. Wants to test each student with exactly one problem from one of his sets.
 * Reuse is prohibited.
 * Student j has skill level S_j, so tester wants to give a problem with difficulty S_j.
 * It may not be possible, so give P_j with |P_j - S_j| minimal and not already given to any other student before jth student.
 * In case of ties, always choose the easier problem.
 * Since jth selection affects later students, keep order.
 * As keeping track of all the problems can be fairly complicated, determine which problems should be given to all students.
 * Input:
 * T
 * for each test case:
 * N, M.
 * N lines: A_i B_i.
 * M integers S_i.
 * Problem: Since N <= 10^5 and M <= 10^5, O(N*M) may cause TLE.
 * For the small set, this might work still.
 */

int main(){
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int N, M;
    bool avail[1001] = {false};
    cin >> N >> M;
    int left, right;
    for(int i=0; i<N; i++){
      cin >> left >> right;
      for(int j=left; j<=right; j++)
        avail[j] = true;
    }
    vector<int> skills = vector<int>(M, 0);
    for(int i=0; i<M; i++)
      cin >> skills[i];
    cout << "Case #" << t << ": ";
    for(int i=0; i<M; i++){
      int abs = 0;
      while(1){
        if (skills[i] - abs >= 1 && avail[skills[i] - abs] == true){
          avail[skills[i] - abs] = false;
          cout << skills[i] - abs << " ";
          break;
        } else if (skills[i] + abs <= 1000 && avail[skills[i] + abs] == true){
          avail[skills[i] + abs] = false;
          cout << skills[i] + abs << " ";
          break;
        } else abs++;
      }
    }
    cout << "\n";
  }
  return 0;
}
