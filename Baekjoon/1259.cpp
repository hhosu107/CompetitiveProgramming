#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n > 0){
    int rev = 0;
    int orig = n;
    while (orig > 0) {
      rev = 10 * rev + (orig % 10);
      orig /= 10;
    }
    if (n == rev) cout << "yes\n";
    else cout << "no\n";
    cin >> n;
  }
  return 0;
}
