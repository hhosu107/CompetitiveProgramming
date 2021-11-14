#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
 * Given string S with len N, digits 0~9.
 * Rotate these operations in the order: Find all the substrs 01 -> replace to 2 / 12 -> 3 / ...
 * Repeat until none of the above operations change the string.
 * Find how the final string will look like.
 * Sol) small: brute force.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  vector<string> patterns = vector<string>(10);
  vector<string> aims = vector<string>(10);
  for(int i=0; i<10; i++){
    patterns[i] = string(1, (char)(i + '0')) + string(1, (char)((i + 1) % 10 + '0'));
    aims[i] = string(1, (char)((i + 2) % 10 + '0'));
  }
  for (int t=1; t<=T; t++){
    int len;
    string p;
    cin >> len >> p;
    int ord = 0;
    int unchanged = 0;
    while (unchanged < 10) {
      size_t pos = p.find(patterns[ord], 0);
      while(pos != string::npos) {
        unchanged = -1;
        p.replace(pos, 2, aims[ord]);
        pos = p.find(patterns[ord], pos);
      }
      unchanged++;
      ord = (ord + 1) % 10;
    }
    cout << "Case #" << t << ": " << p << '\n';
  }
  return 0;
}
