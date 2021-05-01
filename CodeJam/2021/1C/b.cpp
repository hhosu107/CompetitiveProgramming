#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/*
 * B. Roaring years
 * A number is roaring if it can be written with the concatenation of i(i+1)(i+2)...(i+k).
 * (Increasing, distinct consecutive, constructed with at least two integers.)
 * Ex) 2021: concat(20,21), 789: concat(7,8,9)
 * Given the current year (may or may not be roaring), find the "next roaring year".
 * Input: Y (year)
 * small: Y <= 10^6
 * Large: Y <= 10^18
 * Problem: Treat as the "string". The answer can exceed long long.
 * Problem 2: If the given Y starts with a_i and the roaring year starting with a_i is smaller than the given one,
 * is the next roaring year must be (a_i + 1)(a_i + 2)...? May be not, I guess.
 * ex) 68000 -> 78910.
 * Then, can we select the result between only two candidates? (a_i)(a_i+1) ... vs (a_i + 1)(a_i + 2)...? I think it isn't.
 * Ex) 98 -> The next is 123, not 1011.
 * Hmm....
 * 998999 -> 9991000? Maybe not. 7891011 exists.
 * But, can we restrict the type of the roaring year?
 * Ex) 2 digits: 8 kinds. 12, 23, ..., 89 -> 8 kinds
 * 3 digits: 123, 234, ..., 789, 910 -> 8 kinds
 * 4 digits: 1011~9899 and 8910 and 1234, ..., 6789. -> 96 kinds
 * 5 digits: 1 * 5 digits, 1*3 + 2 * 1 digits, 1 + 2*2 digits, 2 + 3 digits: 12345, ..., 56789, 78910, 91011, 99100. -> 8 kinds
 * 6 digits: 1 * 6 digits, 1*4 + 2*1 digits, 1*2 + 2*2 digits, 2*3 digits, 3*2 digits. -> 
 * 123456, 456789, 678910, 891011, 101112, ..., 979899, 100101, ..., 998999. -> 4 + 2 + 88 + 899
 * 7 digits: Just use 1234567; since others are bigger (1*5 + 2 digits, 1*3 + 2*2 digits, 1*1 + 2*3 digits, 2*2 + 3 digits, 3*4 digits are just bigger.) -> 1.
 * 8 + 8 + 96 + 8 + 993 + 1 = 1114 kinds.
 * For small problem, make that database and do the binary search (or even linear)
 */
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  vector<string> smallRoar = vector<string>(1114);
  // 2 digits
  int cnt = 0;
  for(int i=1; i<=8; i++){
    string x = to_string(i) + to_string(i + 1);
    smallRoar[cnt] = x;
    cnt++;
  }
  // 3 digits
  for(int i=1; i<=7; i++){
    string x = to_string(i) + to_string(i + 1) + to_string(i + 2);
    smallRoar[cnt] = x;
    cnt++;
  }
  smallRoar[cnt] = "910";
  cnt++;
  // 4 digits
  for(int i=1; i<=6; i++){
    string x = to_string(i) + to_string(i+1) + to_string(i+2) + to_string(i+3);
    smallRoar[cnt] = x;
    cnt++;
  }
  for(int i=10; i<=98; i++){
    string x = to_string(i) + to_string(i + 1);
    smallRoar[cnt] = x;
    cnt++;
  }
  smallRoar[cnt] = "8910";
  cnt++;
  // 5 digits
  // 1*5
  for(int i=1; i<=5; i++){
    string x = to_string(i) + to_string(i+1) + to_string(i+2) + to_string(i+3) + to_string(i+4);
    smallRoar[cnt] = x;
    cnt++;
  }
  // 1*3 + 2
  smallRoar[cnt] = "78910";
  cnt++;
  // 1*1 + 2*2
  smallRoar[cnt] = "91011";
  cnt++;
  // 2 + 3
  smallRoar[cnt] = "99100";
  cnt++;
  // 6 digits
  // 1*6
  for(int i=1; i<=4; i++){
    string x = to_string(i) + to_string(i+1) + to_string(i+2) + to_string(i+3) + to_string(i+4) + to_string(i+5);
    smallRoar[cnt] = x;
    cnt++;
  }
  // 1*4 + 2
  smallRoar[cnt] = "678910";
  cnt++;
  // 1*2 + 2*2
  smallRoar[cnt] = "891011";
  cnt++;
  // 2*3
  for(int i=10; i<=97; i++){
    string x = to_string(i) + to_string(i+1) + to_string(i+2);
    smallRoar[cnt] = x;
    cnt++;
  }
  // 3*2
  for(int i=100; i<=998; i++){
    string x = to_string(i) + to_string(i+1);
    smallRoar[cnt] = x;
    cnt++;
  }
  // 7 digits
  smallRoar[cnt] = "1234567";
  cnt++;
  // sort roaring ones
  vector<ll> sorted_roar = vector<ll>(1114);
  for(int i=0; i<1114; i++){
    sorted_roar[i] = stol(smallRoar[i]);
  }
  sort(sorted_roar.begin(), sorted_roar.end());
  int T;
  ll Y;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> Y;
    cout << "Case #" << t << ": ";
    if (Y >= 1000000){
      cout << sorted_roar[1113] << endl;
      continue;
    }
    for(int i=0; i<1114; i++){
      if(sorted_roar[i] > Y){
        cout << sorted_roar[i] << endl;
        break;
      }
    }
  }
  return 0;
}
/* ...
 * How many roaring years exist? Can we restrict the count?
 * Ex) 8 digits: 10111213 ~ 96979899 and 67891011 and 99100101.
 * Caution: With the input 101, 102 cannot be the roaring one since 02 has leading zero.
 * For the maximum...
 * 9 digits: 1 * 9 + 2 * 5 digits, 2 * 8 digits + 3 * 1 digit, 2 * 5 + 3 * 3, 2 * 2 + 3 * 5., 3 * x + 4*y, 4*1 + 5*3, 6*2 + 7, 9 + 10, ...,
 * but the least one is 1 * 9 + 2*5 digits, which is 1234567891011121314.
 * -> 9293949596979899100, 9596979899100101102, 9899100101102103104.
 *  To be honest, for the 18 digits, there are 100000000100000001 ~ 999999998999999999.
 *  Other combinations can be 1 * 8 + 2*5 digits, ..., 2 * 9 digits, 2 * 6 + 3*2 ~ 3 * 6 digits, 3 * 2 + 4*3 digits, 4 * 2 + 5*2 digits, 6 * 3 digits. How should we order these irregular ones with 9 * 2 digit-ed ones?
 *  We cannot order all of them, but we can order the other combinations.
 */
