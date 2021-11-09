#include<iostream>
using namespace std;

int main () {
  int n;
  int min = 1000001, max = -1000001;
  int c;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> c;
    if (min > c) min = c;
    if (max < c) max = c;
  }
  cout << min << " " << max << endl;
  return 0;
}
