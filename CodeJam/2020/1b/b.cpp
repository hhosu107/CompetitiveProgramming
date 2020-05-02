#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/* B. 2*10^9 * 2*10^9 square, dart with radius between A and B, fully contained, may touch its edges, center is located at the integer point from each edge of the wall.
 * Help to hit the center of the dart. For each answer, program will tell whether the dart hit the dartboard.
 * Guess within 300 darts.
 * A = B = 10^9 - 5 for small, 10^9 - 50 for middle, 10^9/2 and 10^9 for large.
 */

bool B1() {
  for(int i=-5; i<=5; i++){
    for(int j=-5; j<=5; j++){
      cout << i << " " << j << '\n' << flush;
      string res;
      cin >> res;
      if (res.compare("CENTER") == 0) {
        return true;
      }
    }
  }
  return false;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, A, B;
  cin >> T >> A >> B;
  for (int t=1; t<=T; t++){
    bool x = B1();
    if(!x) break;
  }
  return 0;
}

int gcd(int a, int b){
  if (a%b == 0) return a;
  else return (b, a%b);
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}
