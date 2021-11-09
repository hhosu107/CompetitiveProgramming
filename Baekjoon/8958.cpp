// BOJ 8958 OX quiz
#include<iostream>
#include<string>
using namespace std;

int main () {
  int n;
  string ox;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> ox;
    int mod = 0;
    int sum = 0;
    for(char c : ox){
      if (c == 'O'){
        mod++;
        sum += mod;
      } else {
        mod = 0;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
