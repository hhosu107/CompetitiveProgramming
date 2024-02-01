/* Sol)
Focus on each character, not the substring itself.
To contain a character as a unique character, the substring that contains that
character must not contain any other same character. Thus, when we start at
index i, we cannot go left more if there is a same character / vice versa for
right. Thus, save each occurrence index into vector<int> cnt[26], insert -1 / n
as left/right padding, and count number of substrings that contains each unique
character. Then each counting occurs uniquely for each unique selection of the
character.
*/
using ll = long long;
class Solution {
public:
  ll add(ll a, ll b) { return (a) + (b); }
  ll mul(ll a, ll b) { return (a) * (b); }
  int uniqueLetterString(string s) {
    int n = s.size();
    int ans = 0;
    vector<int> cnt[26];
    for (int i = 0; i < n; i++) {
      char x = s[i];
      if (cnt[x - 'A'].size() == 0) {
        cnt[x - 'A'].push_back(-1);
      }
      cnt[x - 'A'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i].size() == 0)
        continue;
      cnt[i].push_back(n);
      for (int j = 1; j < cnt[i].size() - 1; j++) {
        ll temp = mul(
            cnt[i][j] - cnt[i][j - 1],
            cnt[i][j + 1] -
                cnt[i]
                   [j]); // If a character 'A' + i is contained in a substring,
                         // find its index. To add it as a unique character, the
                         // substring containing this index cannot exceed the
                         // previous index and the next index. Here, the current
                         // index is cnt[i][j], previous index is cnt[i][j-1]
                         // (-1 if leftmost), next index is cnt[i][j+1] (n if
                         // rightmost). Here, the substring can reach at the
                         // right index of the previous index, and at the left
                         // index of the next index, where each direction has
                         // (cnt[i][j] - cnt[i][j-1]) selections and (cnt[i][j +
                         // 1] - cnt[i][j]) selections.
        ans = add(ans, temp);
      }
    }
    return ans;
  }
};
