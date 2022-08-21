#include <bits/stdc++.h>

using namespace std;

/* 3. P is palindrome. find shortest palindromic Q that makes PQ palindrome.
Sol) Q is a reversed prefix of P (to match with prefix part of P), but which means that Q is a suffix of P.
Thus, find a largest index (smaller than P.length) in P such that P+P[idx:] is a palindrome.
The largest Q is P itself, since rev(p) = P.
Here, this means: P[0:idx] == p[len-idx:] is a palindrome (otherwise, rev(P[idx:]) + P[len-idx:] + P[idx:] cannot be palindrome)
Thus, find longest suffix of P that both suffix and prefix is palindrome (that suffix can be an empty string).
1) Use Manacher's algorithm to find longest palindrome in P that centers at each index.
2) do the following:
for (i from len + 1 to 2 * len):
  check manacher[i - len] == i - len + 1 (starting at this index as center is a prefix as palindrome)
  check manacher[i] == 2 * len + 1 - i (starting at this index as center is a suffix as palindrome)
  (here, always inequality <= holds, so the string can be splited in two palindromes iff both equality holds.)
  Thus, to sum up, check manacher[i - len] + manacher[i] == len + 2.
3) output the first index i - len, and get the prefix with length i - len
4) that is the answer (since prefix itself should be the palindrome, we don't have to reverse it.)
*/

vector<int> manacher_odd(string s)
{
  int n = s.size();
  s = "$" + s + "^";
  vector<int> p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++)
  {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (s[i - p[i]] == s[i + p[i]])
    {
      p[i]++;
    }
    if (i + p[i] > r)
    {
      l = i - p[i];
      r = i + p[i];
    }
  }
  return vector<int>(begin(p) + 1, end(p) - 1); // eliminates "$" and "^"
}

vector<int> manacher(string s)
{
  string t;
  for (auto c : s)
  {
    t += string("#") + c;
  }
  vector<int> res = manacher_odd(t + "#");
  return vector<int>(begin(res), end(res));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> palindrome_len = manacher(s);
    int prefix_len = 0;
    for (int i = n + 1; i <= 2 * n; i++)
    {
      if (palindrome_len[i] + palindrome_len[i - n] == n + 2)
      {
        prefix_len = i - n;
        break;
      }
    }
    string prefix = s.substr(0, prefix_len);
    cout << "Case #" << t << ": " << prefix << '\n';
  }
  return 0;
}
