#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct dict {
  string word;

  dict() {word = "";}
  dict(string w) : word(w) {}

  bool operator<(const dict& r) const {
    return (word.length() < r.word.length() || (word.length() == r.word.length() && word.compare(r.word) < 0));
  }
  bool operator==(const dict& r) const {
    return (word.compare(r.word) == 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<dict> words = vector<dict>(n);
  string x;
  for(dict& w: words){
    cin >> w.word;
  }
  sort(words.begin(), words.end());
  words.erase(unique(words.begin(), words.end()), words.end());
  for(auto d: words)
    cout << d.word << '\n';
  return 0;
}
