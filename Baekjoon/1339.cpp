#include<bits/stdc++.h>
using namespace std;

/* 1339
 * Given n and n composed of at most 10 different upper alphabets,
 * give 0 ~ 9 to each alphabet to make the biggest sum of them.
 * Sol)
 * length(word) <= 8.
 * Thus, construct an array for each alphabet:
 * x[alphabet][i \in [0, 7]] = # occurrence of alphabet in the word on ith
 * position.
 */

class a_occ {
  int contrib = 0;
public:
  char alpha;
  vector<int> occ;
  a_occ() : alpha(' '), occ(vector<int>(8, 0)) {}
  a_occ(char a, vector<int> o) : alpha(a), occ(o) {}
  void set_contrib() { // Set contribution of this alphabet.
    // What I thought wrong is that:
    // * Then we compare each alphabet by:
    // *    compare x[alphabet][7] with x[beta][7]. If the former is larger, give the
    // *    larger number for that.
    // *    Compare ...6, ..., 0.
    int base = 1;
    for(int i=0; i<8; i++) {
      contrib += occ[i] * base;
      base *= 10;
    }
  }
  int get_contrib() {
    return contrib;
  }
  bool operator<(const a_occ &b) const {
    return contrib > b.contrib;
  }
};

int main () {
  int n;
  cin >> n;
  vector<string> words = vector<string>(n);
  for (string &w: words) cin >> w;
  vector<a_occ> alphas = vector<a_occ>(26);
  for(int i=0; i<26; i++)
    alphas[i].alpha = (char)('A' + i);
  for (string w: words) {
    int len = w.length();
    for(int i=len-1; i >= 0; i--) {
      char c = w[i];
      int idx = (int)(c - 'A');
      alphas[idx].occ[(len-1)-i]++;
    }
  }
  for(a_occ &a: alphas)
    a.set_contrib();
  sort(alphas.begin(), alphas.end());
  for(int i=0; i<10; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<words[j].length(); k++) {
        if (words[j][k] == alphas[i].alpha)
          words[j][k] = (char)('0' + (9 - i));
      }
    }
  }
  int sum = 0;
  for_each(words.begin(), words.end(), [&sum](string &w) {
    sum += stoi(w);
    });
  cout << sum << '\n';
  return 0;
}
