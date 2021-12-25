#include<iostream>
using namespace std;

int main () {
  int n;
  int sum = 0;
  while(1) {
    cin >> n;
    if (n == -1) break;
    sum += n;
  }
  cout << sum << endl;
  return 0;
}
