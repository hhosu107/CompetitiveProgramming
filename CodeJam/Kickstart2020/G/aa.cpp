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
int kick[25000];
int stt[20000];
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
    int ks = 0, ke = 0;
    int ss = 0, se = 0;
    for(int i=0; i<len; i++){
      if(S[ke] == k[ke - ks]){
        ke++;
        if (ke - ks == 4){
          kick[klen] = ks;
          ks = ke = i + 1;
          klen++;
        }
      } else { ks = ke = i + 1; }
      if(S[se] == s[se - ss]){
        se++;
        if(se - ss == 5){
          stt[slen] = ss;
          ss = se = i + 1;
          slen++;
        }
      } else { ss = se = i + 1; }
    }
    int ans = 0;
    int sidx = 0;
    for(int i=0; i<klen; i++){
      while(kick[i] > stt[sidx]) {
        sidx++;
      }
      ans += slen - sidx;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }

  return 0;
}

