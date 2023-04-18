#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
using ll = long long;

ll string_to_hash(string x, unordered_map<char, ll> &charint) {
  ll val = 0;
  ll length_modifier = 1000000000000;
  int len = x.size();
  for(int i=0; i<len; i++) {
    val = 10 * val + charint[x[i]];
  }
  return val + length_modifier * len;
}

int main () {
  int T, N;
  cin >> T;
  for(int t=1; t<=T; t++) {
    unordered_map<char, ll> charint;
    for(int i=0; i<26; i++) {
      int x;
      cin >> x;
      charint[(char)(i+(ll)('A'))] = x;
    }
    cin >> N;
    unordered_set<ll> hash_val;
    bool collision = false;
    for(int i=0; i<N; i++) {
      string x;
      cin >> x;
      ll hashed = string_to_hash(x, charint);
      if (hash_val.find(hashed) != hash_val.end()) {
        collision = true;
      }
      hash_val.insert(hashed);
    }
    cout << "Case #" << t << ": " << (collision ? "YES\n" : "NO\n");
  }
  return 0;
}

