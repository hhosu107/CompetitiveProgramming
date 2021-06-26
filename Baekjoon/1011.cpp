#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
/* Sol) move = 2*n -> up to n(n+1) steps / move = 2*n - 1 -> up to n^2 steps */
int main(){
  int T, x, y;
  cin >> T;
  for(int t=0; t<T; t++){
    cin >> x >> y;
    int dist = y - x;
    for(int i=1; i<=(int)sqrt(dist) * 2 + 1; i++){
      long long int half = (i + 1) / 2;
      long long int cap = (i % 2 == 1 ? half * half : half * (half + 1));
      if (dist <= cap) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
