#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int partsum = 0;
  for(int i=n-54; i<n; i++){
    int k = i;
    int remsum = 0;
    while (k > 0){
      remsum += k % 10;
      k /= 10;
    }
    if (i + remsum == n) {
      partsum = i;
      break;
    }
  }
  cout << partsum << endl;
  return 0;
}
