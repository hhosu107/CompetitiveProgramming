#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* A. Closest pick
 * N tickets, ticker number btwn 1 and K. Inclusive.
 * Some tickets can have same integer.
 * Each number on the sold ticket is known.
 * Maximize odds of winning by purchasing two tickets.
 * Last customer.
 * Let two tickets are a and b.
 * If randomly chosen integer c is strictly closer to one of the bought ticket than all other tickets or if both of the tickets are the same distance to c & closer than all other tickets, win the raffle.
 * Given the integers "on the N tickets", what is the maximum probability of winning the raffle?
 * N less than 31, 1<=K<=30 (small), <=10^9 (large)
 * Sol)
 * Sort N integers first.
 * Then we can win on the raffle at such segments:
 * If 1 <= a1 <= .. <= an <= K,
 * segment 1's length: a1 - 1,
 * segment i's length: floor((a_i - a_i-1) / 2),
 * segment n+1's length: K - an.
 * If both selection is made inside a single segment (except 1st and n+1th), (a_i - a_i-1) - 1.
 * Since we will select the largest ones, our selection will be made as this:
 * If a1 - 1 >= any other (a_i - a_i-1) / 2, select a1-1. Vice versa for K - an.
 * And thus, if both selection are made on the left end / right end, that's the result.
 * If both a1 - 1 < one of (a_i - a_i-1) / 2 and K - a_n < one of (a_i - a_i-1) are true,
 * then the result will be max(max((a_i - a_i-1) / 2) + 2ndmax((a_i - a_i-1)/2), max(a_i - a_i-1) - 1).
 * Now implement.
 */
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N, K;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N >> K;
    vector<ll> tickets = vector<ll>(N, 0L);
    for(int i=0; i<N; i++)
      cin >> tickets[i];
    sort(tickets.begin(), tickets.end());
    cout << "Case #" << t << ": ";
    if (N == 1) {
      cout << (double)(K-1) / (double)K << endl;
      continue;
    }
    vector<ll> tidiff = vector<ll>(N-1, 0L);
    for(int i=0; i<N-1; i++){
      tidiff[i] = tickets[i+1] - tickets[i];
    }
    sort(tidiff.begin(), tidiff.end(), greater<ll>());
    ll left_end = tickets[0] - 1;
    ll right_end = K - tickets[N-1];
    ll answer = 0;
    int used_seg = 0;
    if (left_end >= (tidiff[0] / 2L)){
      answer += left_end;
      used_seg += 1;
    }
    if (right_end >= (tidiff[0] / 2L)){
      answer += right_end;
      used_seg += 1;
    }
    if (used_seg == 2){
      cout << (double)answer / (double)K << endl;
    } else {
      if (used_seg == 1) {
        cout << (double)(answer + (tidiff[0] / 2L)) / (double)K << endl;
      } else {
        if (N > 2 && tidiff[0] == tidiff[1]) {
          cout << (double)((tidiff[0] / 2L) + (tidiff[1] / 2L)) / (double)K << endl;
        } else {
          cout << (double)(tidiff[0] - 1) / (double)K << endl;
        }
      }
    }
  }
  return 0;
}
