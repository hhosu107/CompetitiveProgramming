#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> orig = vector<int>(n);
  for(int i=0; i<n; i++){
    cin >> orig[i];
  }
  sort(orig.begin(), orig.end());
  int sum = 0;
  if(n % 2 == 0){
    for(int i=0; i<n/2; i++){
      sum -= orig[i];
    }
    for(int i=0; i<n/2-1; i++){
      sum -= orig[i];
    }
    for(int i=n/2; i<n; i++){
      sum += orig[i];
    }
    for(int i=n/2 + 1; i<n; i++){
      sum += orig[i];
    }
  }
  else{
    for(int i=0; i<(n-1)/2; i++){
      sum -= 2 * orig[i];
    }
    for(int i=(n-1)/2; i<n; i++){
      sum += 2 * orig[i];
    }
    sum -= (orig[(n-1)/2] + orig[(n+1)/2]);
  }
  cout << sum << endl;
  return 0;
}
