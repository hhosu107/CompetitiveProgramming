#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<functional>
using namespace std;
/* B
 * server receives a request in the form of a single positive integer M of up to U decimal digits
 * and then respond with an integer from the range 1~M at random.
 * But overrandomized: Each server has a random subset of 10 distinct uppercase english letters to use as digits, and a random mapping from those letters to unique values between 0 and 9.
 * Digit string D which defines the mapping between letters and the base: D's jth character from the left is the base 10 digit of value j.
 * When receiving i-th query with an int param M_j, the server:
 * chooses an integer N_j at tandom from the inclusive range 1 thru M_j,
 * writes it as a base 10 wieh no leading zeros using j-th character of D,
 * returns the resulting string.
 * We send 10^4 queries to each server.
 * For each query, we choose M_j between 1~10^U-1 inclusive, and receive the response R_j.
 * Input:
 * T.
 * U as digit size
 * 10^4 lines of Q_i and R_i.
 * If Q_i == -1, M_i is unknown. Otherwise Q_i == M_i.
 * Output Case #x: y where y is digit string D.
 * Test 3: Q_i = -1 for all i. Otherwise, Q_i = M_i.
 */
typedef long long int ll;
typedef struct bds{
  ll bd;
  string rands;
}bds;

struct less_than{
  inline bool operator() (const bds& s1, const bds &s2){
    return s1.bd < s2.bd;
  }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int U;
    int m;
    string res;
    vector<bds> qr = vector<bds>(10000);
    cin >> U;
    for(int i=0; i<10000; i++){
      cin >> qr[i].bd >> qr[i].rands;
    }
    std::sort(qr.begin(), qr.end(), less_than());
    vector<char> mapp = vector<char>(10, ' ');
    bool marked[10] = {false};
    vector<char> usedc = vector<char>();
    for(bds q: qr){
      if(q.bd == 1){
        if(!marked[1]){
          mapp[1] = q.rands[0];
          marked[1] = true;
        }
      }
      else if (q.bd <= 9){
        bool dup = false;
        for(int i=1; i<= q.bd-1; i++){
          if(q.rands[0] == mapp[i]){
            dup = true;
            break;
          }
        }
        if (!dup) {
          if(!marked[q.bd]){
            mapp[q.bd] = q.rands[0];
            marked[q.bd] = true;
          }
        }
      }
      else {
        if(q.rands.size() == 2){
          int k = 1;
          for(; k<10; k++){
            if(mapp[k] == q.rands[1]) break;
          }
          if (k == 10){
            mapp[0] = q.rands[1];
            break;
          }
        }
      }
      int ccnt = 0;
      int len = usedc.size();
      for(; ccnt<len; ccnt++){
        if(usedc[ccnt] == q.rands[0])
          break;
      }
      if (ccnt == len){
        usedc.push_back(q.rands[0]);
      }
    }
    cout << "Case #" << t << ": ";
    for(int i=0; i<10; i++){
      cout << mapp[i];
    }
    cout << endl;
  }
  return 0;
}
