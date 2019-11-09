#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// A: just compute all disabled numbers, sort, and exclude all positive integers from 1.
int main(){
  int a[1001];
  a[0] = a[1] = 1;
  int n;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int k=2; k<=n; k++){
    vector<int> disab = vector<int>(k/2);
    for(int j=1; k - 2*j >= 0; j++){
      disab[j-1] = 2 * a[k-j] - a[k-2*j];
    }
    sort(disab.begin(), disab.end());
    int ans = disab[k/2-1] + 1;
    int i=0;
    while(disab[i] < 1){
      i++;
    }
    if(disab[i] > 1){
      ans = 1;
    }
    else {
      for(; i<k/2; i++){
        if(i != k/2 - 1 && disab[i] + 1 < disab[i+1]){
          ans = disab[i] + 1;
          break;
        }
      }
    }
    a[k] = ans;
  }
  cout << a[n] << '\n';
  return 0;
}
