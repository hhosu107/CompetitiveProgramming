#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* C. Rock-Paper-Scissors 60 times per day.
 * If the choice wins, get W. If the choice draws, get E. Else, nothing.
 * Friend's strategy: keep track how many times I chose R, P, S so far during
 * that day. Let A_i be the choce of R, P, or S on round i, B_i be the choice of
 * the friend. Let r_i be the number of times A_j = R for 1<=j<=(i-1), and
 * similarly define p_i, s_i.
 * When the friend decides B_i, Pr[R] = s_i/(i-1), PR[P] = r_i/(i-1), PR(S) =
 * p_i/(i-1).
 * Let X be the average reward to get in this game after T days. Given W and E
 * (different values for different days), provide the instruction(constant) as a
 * string of 60 characters, so that the average expected value of the reward
 * across all the days is at least X.
 * Note that you can choose different instructions for different values of W and
 * E.
 * T = 200, 50 <= W <= 950, 0 <= E <= W: one of W, W/2, W/10, 0.
 * X = 14600, 15500, 16400.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, K, N;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ": ";
  }
  return 0;
}
