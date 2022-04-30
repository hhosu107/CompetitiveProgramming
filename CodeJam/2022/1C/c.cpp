#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

// C. ASeDatAb
// Database stores values as records that hold 8-bit bin strings.
// Each record is 8-bit binary string.
// indexed from left to right, 0~7.
// When an instruction to set a specific record to a new value V is received,
// Do the following:
// 1. Choose r \in [0, 7], W = rotate_right(V, r), i.e., w = V[8-r:7] +
// V[0:7-r].
// 2. Replace X = X ^ W.
// 3. Return the number of bits that are 1 in the new value to the user.
// No matter of the initial value, a use can make the record as 00000000 with
// instructions up to 300.

int main(){
  int ans, N;
  int T;
  scanf("%d", &T);
  while(T--) {
    bool failed = false;
    bitset<8> x;
    for(int tr=0; tr<300; tr++) {
      x = bitset<8>(tr);
      cout << x << endl;
      scanf("%d", &ans);
      if (ans == 0) {
        break;
      } else if (ans == -1) {
        failed = true;
        break;
      }
    }
    if (failed) break;
  }
  return 0;
}
