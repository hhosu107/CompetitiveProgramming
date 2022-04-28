#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  string a, b;
  cin >> a >> b;
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
  for(int i=0; i<=a.size(); i++) {
    for(int j=0; j<=b.size(); j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  int index = dp[a.size()][b.size()];
  cout << index << endl;
  if (index == 0)
    return 0;
  vector<char> lcs_string(index);
  int i = a.size(), j = b.size();
  while(i > 0 && j > 0) {
    if(a[i-1] == b[j-1]) { // Current character matches, i.e., LCS contains this character
      lcs_string[index - 1] = a[i-1];
      i--;
      j--;
      index--;
    } else if (dp[i-1][j] > dp[i][j-1]) { // Current character does not match, so we backtrack the one that generated dp[i][j].
      i--;
    } else { // vice versa.
      j--;
    }
  }
  for(auto c: lcs_string)
    cout << c;
  cout << endl;
  return 0;
}
