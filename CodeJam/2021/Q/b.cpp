#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// B. Moons/Umbrellas
// For given string s constructed only with C and J, every occurrence of CJ pays X, JC pays Y.
// To pay minimal price, fill the empty spaces.
// Ex) CJ?CC?: CJCCCC, CJCCCJ, CJJCCC, CJJCCJ are possible; third/first options pay X+Y, second/fourth options pay 2X + Y.
// Given the costs X and Y, compute the minimal payment.
// Sol) For consecutive ?s, fill with only one character.
// If left adjacent character and right adjacent character differs, fill with one that pays less. Otherwise, pays nothing.
// For the rest of the string, just compute.
// Extra: "NEGATIVE COST". -> In this case, we can decide how to alter.
// ex) J....J: for the length odd(2n-1), CJCJC...JC makes n(X+Y).
// ex) J....J: for the length even(2n), what is the best? -> whatever, it maximally makes n(X+Y).
// For the same endpoints, there are only two choices, paid nothing, or pay n(X+Y) that is negative.
// ex) J....C: At least one alternation JC occurs. i.e., Y + k(X+Y) occurs.
// Also there are two cases: if X + Y < 0, Y + (n-1)(X+Y) is the best; otherwise Y is the base.
// For C...J, it is vice versa as X vs X + (n-1)(X+Y).
// For this case, we should also consider end points.
// For ...C, we should compare 0, Y, and Y + (n-1)(X+Y). If X+Y > 0, pick 0 or Y. Otherwise, pick 0 or Y + (n-1)(X+Y). same as ...J, and for alter endpoint.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  string ss;
  int T, X, Y;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> X >> Y >> ss;
    int len = ss.length();
    int idx = 0;
    int cost = 0;
    while(idx < len){
      if (ss[idx] == '?'){
        char left = '?';
        if(idx > 0) left = ss[idx-1];
        while(idx < len - 1 && (ss[idx+1] == '?')) idx++;
        char right = '?';
        if(idx < len - 1) right = ss[idx+1];
        if (left != '?' && right != '?'){
          if (left != right) {
            if (left == 'J') cost += Y;
            else cost += X;
          }
        }
        idx++;
      }
      else{
        if (idx > 0){
          if (ss[idx] != ss[idx - 1]){
            if (ss[idx - 1] == 'J') cost += Y;
            else cost += X;
          }
        }
      }
      idx++;
    }
    cout << "Case #" << t << ": " << cost << endl;
  }
  return 0;
}
