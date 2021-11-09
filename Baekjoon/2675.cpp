#include<iostream>
#include<string>
using namespace std;

int main () {
  int t;
  int r;
  string s;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> r >> s;
    for(char c : s) {
      for(int i=0; i<r; i++)
        cout << c;
    }
    cout << endl;
  }
  return 0;
}
