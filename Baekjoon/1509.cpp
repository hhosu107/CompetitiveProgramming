#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/* 1509. Dividing into smallest number of palindromes.
 * Sol) Upon ith index, we can make dp equation as:
 * dp[i] = min (dp[i-k] + 1) for all k such that str[i-k+1..i] is palindrome.
 * Thus, we store palindrome's length into vector<vector<int>> where the
 * palindrome ends at index i and the length is l.
 * Since n<=2500, n^2 is enough to find all palindromes.
 */

int main () {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(n + 1, 3000);
  vector<vector<int>> palindromes(n, vector<int>());
  dp[0] = 0;
  dp[1] = 1;
  for(int i=0; i<2 * n-1; i++) {
    for(int j=(i % 2); i-j>=0 && i+j<2 * n - 1; j += 2) {
      if (s[(i-j) / 2] == s[(i+j) / 2]) {
        palindromes[(i+j) / 2].push_back(j + 1);
      } else break;
    }
  }
  for(int i=2; i<=n; i++) {
    for(auto x: palindromes[i-1]) {
      dp[i] = min(dp[i], dp[i-x] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
