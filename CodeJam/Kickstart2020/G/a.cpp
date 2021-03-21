#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/* A. Kick_Start
 * fragment = substring of the text.
 * Can find a fragment like 'KICK%START'?
 * Count number of different lucky fragments. */
/* Sol: count KICK with position, Start with position.
 * Then with binary search, find the number of segments of START that appears
 * after KICK.*/

char k[5] = "KICK";
char s[6] = "START";
int kick[33334];
int stt[20001];
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  string S;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> S;
    int len = S.length();
    int klen = 0, slen = 0;
    int ks = 0;
    int ss = 0;
    for(int i=0; i<len; i++){
      if(S[i] == k[i - ks]){
        if (i - ks == 3){
          kick[klen] = ks;
          ks = i;
          klen++;
        }
      } else {
        if (S[i] == 'K') {
          ks = i;
        } else ks = i + 1;
      }
      if(S[i] == s[i - ss]){
        if(i - ss == 4){
          stt[slen] = ss;
          ss = i + 1;
          slen++;
        }
      } else ss = i + 1;
    }
    int ans = 0;
    int sidx = 0;
    for(int i=0; i<klen; i++){
      while(kick[i] > stt[sidx]) {
        sidx++;
        if (sidx >= slen) break;
      }
      if (sidx >= slen) break;
      ans += slen - sidx;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }

  return 0;
}

