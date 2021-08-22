#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// A. Shuffled anagram: For A, shuffled anagram S is shuffled iff for all i, S[i] != A[i].

struct charSize {
  int idx, size;
  charSize() {idx = 0; size = 0;}
  charSize(int idx, int size) : idx(idx), size(size) {}
  bool operator<(charSize& right) const {
    return (size > right.size) || (size == right.size && idx > right.idx);
  }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    vector<vector<int>> charPos = vector<vector<int>>(26, vector<int>());
    char anagram[40002] = "";
    string s;
    cin >> s;
    cout << "Case #" << t << ": ";
    for(int i=0; i<s.length(); i++){
      charPos[(int)(s[i] - 'a')].push_back(i);
    }
    vector<charSize> charSizes = vector<charSize>(26);
    for(int i=0; i<26; i++){
      charSizes[i] = charSize(i, charPos[i].size());
    }
    sort(charSizes.begin(), charSizes.end());
    if (charSizes[0].size * 2 > s.size()){
      cout << "IMPOSSIBLE\n";
      continue;
    }
    int anagramIdx = 0;
    int anagramPosIdx = 0;
    for(int i=25; i>=0; i--){
      for(int j=0; j<charSizes[i].size; j++){
        if (anagramPosIdx == charSizes[anagramIdx].size){
          anagramPosIdx = 0;
          anagramIdx = (anagramIdx == 0 ? 25 : anagramIdx - 1);
          while(charSizes[anagramIdx].size == 0) anagramIdx--;
        }
        anagram[charPos[charSizes[anagramIdx].idx][anagramPosIdx]] = (char)(charSizes[i].idx + 'a');
        anagramPosIdx++;
      }
    }
    cout << anagram << '\n';
  }
  return 0;
}
