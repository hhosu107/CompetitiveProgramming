#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// J: Attach small triangles from big triangle.
// 4: attach triangle at the first side of the big centered triangle.
// 5, 6: attach triangles at the remaining two other side of the big centered triangle.
// 7, 8: attach two triangles at the first triangle attached at the big centered triangle.
// 9~12: attach 4 triangles; 2 for each triangles attached at 5, 6.
// and go forward until the input reaches.
int main(){
  int tri[1000001];
  tri[3] = 0;
  tri[4] = 1;
  tri[5] = tri[6] = 2;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int k=7;
  int wide = 2;
  for(;k<=n;){
    for(int j=k; j<(k+wide <= n ? k + wide : n + 1); j++){
      tri[j] = tri[k-1] + 1;
    }
    k += wide;
    if (k > n){
      break;
    }
    wide *= 2;
    for(int j=k; j<(k+wide <= n ? k + wide : n + 1); j++){
      tri[j] = tri[k-1] + 1;
    }
    k += wide;
  }
  cout << tri[n] << '\n';
  return 0;
}
