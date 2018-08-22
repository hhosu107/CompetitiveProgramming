#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 1152: S = \sum_{i=1}^{n} a_i, {a_i} increasing natural. max n?
// rule:
// 1 : 1, 2 : 2, 3: 1,2, 4: 1,3, 5: 2,3, 6:1,2,3, 7:1,2,4, 8:1,3,4, 9:2,3,4, ...
// count increases by 1 at (n)(n+1)/2 form.

int main(){
  long long int s;
  cin >> s;
  long long int n=1;
  while((n+1) * (n+2) / 2 <= s) n++;
  cout << n << endl;
  return 0;
}
