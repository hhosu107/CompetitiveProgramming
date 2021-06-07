#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// A. Smaller Strings
/* int K, string S with len N \in {a, b, c, ...} (size K)
 * a1, a2, ..., an is lexicographically smaller than another string of the same
 * length b1, ..., bn if a_i < b_i where i is the 'first' index that differs.
 * Palindrome...
 * input:
 * T
 * N, K
 * S
 * output:
 * the number of lexicographically smaller palindrome strings mod 10^9 + 7.
 * Sol) Cut the first half of S, and generate the palindrome with that half.
 * If it is larget than S, count will be reduced by 1.
 */

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  long long int N, K;
  string S;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N >> K;
    cin >> S;
    long long int ans = 0;
    int size_half = N / 2;
    string first_half = S.substr(0, N - size_half);
    string second_half = S.substr(0, size_half);
    string second_half_reversed (second_half.rbegin(), second_half.rend());
    string border_palindrome = first_half + second_half_reversed;
    for(int i=0; i<N - size_half; i++){
      int diff = (int)S[i] - (int)('a');
      ans = (K * ans + diff) % (1000000007);
    }
    if(S.compare(border_palindrome) > 0) {
      ans += 1;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
