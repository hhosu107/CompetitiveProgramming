#include<iostream>

using namespace std;

int main(){
  int a[5001];
  for(int i=0; i<=5000; i++)
    a[i] = 5001;
  a[3] = a[5] = 1;
  int n;
  cin >> n;
  for(int i=6; i<=n; i++){
    int from3 = (a[i-3] + 1);
    int from5 = (a[i-5] + 1);
    a[i] = (from3 < from5 ? from3 : from5);
  }
  cout << (a[n] >= 5001 ? -1 : a[n]) << endl;
  return 0;
}
