#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

// A. Reversort (C. Reversort Engineering is identical to this except for the last paragraph.)
// Reversort: Sort a distinct integers in increasing order, based on the 'reverse' operation.
// Each application of this operation reverses the order of some contiguous part of the list.
// Reversort(L):
//     for i := 1 to length(L) - 1:
//         j := position with the minimum value in L between i and and length(L)
//         reserve(L[i..j])
// After i-1 iterations, positions 1~i-1 of the list contain the i-1 smallest elements of L, in increasing order.
// During the i-th iteration, the process reverses the sublist going from the i-th position to the current position to the current position of the i-th minimum element.
// ex) [4, 2, 1, 3] -(i=1, j=3)> [1, 2, 4, 3] -(i=2, j=2)> [1, 2, 4, 3] -(i=3, j=4)> [1, 2, 3, 4]
// Most expensive part: Reverse operation.
// Measure for the cost of each iteration = length(L[i..j]) == j - i + 1.
// Compute the cost of executing Reversort.
// T <= 100, N <= 100, 1<=L_i<=N, L_i != L_j.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  string ss;
  int T, N, M;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N >> M;
    cout << "Case #" << t << ":" << '\n';
    for (int i=0; i<=2*N; i++) {
      for(int j=0; j<=2*M; j++) {
        if (i + j <= 1) cout << ".";
        else if (i % 2 == 0 && j % 2 == 0) cout << "+";
        else if (i % 2 == 0 && j % 2 == 1) cout << "-";
        else if (i % 2 == 1 && j % 2 == 0) cout << "|";
        else if (i % 2 == 1 && j % 2 == 1) cout << ".";
      }
      cout << "\n";
    }
  }
  return 0;
}
