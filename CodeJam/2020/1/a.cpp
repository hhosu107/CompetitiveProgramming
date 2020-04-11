#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/* A. Given *-included patterns, find a single name of at most 10000 characters. */

/* A1. All P_i contains * at the leftmost. */
string a1(int N, vector<string> &pat){
  int maxlen = -1, maxidx = -1;
  for(int i=0; i<N; i++){
    int len = pat[i].length();
    if (maxlen < len) {
      maxlen = len;
      maxidx = i;
    }
  }
  for(int i=0; i<N; i++){
    string cand = pat[i].substr(1);
    string postfix = pat[maxidx].substr(pat[maxidx].length() - pat[i].length() + 1);
    if(postfix.compare(cand) != 0){
      return "*";
    }
  }
  return pat[maxidx].substr(1);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    vector<string> pat = vector<string>(N);
    for(int i=0; i<N; i++)
      cin >> pat[i];
    cout << "Case #" << t << ": " << a1(N, pat) << endl;
  }
  return 0;
}
