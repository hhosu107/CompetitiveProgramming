#include<iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int zeroth_val = 1;
  for(int i=0; i<n; i++){
    zeroth_val += (3 * (i + 1)) + 1;
    zeroth_val %= 45678;
  }
  cout << zeroth_val << endl;
  return 0;
}
