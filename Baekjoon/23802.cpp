#include<iostream>
#include<string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<5*n; j++){
      cout << '@';
    }
    cout << '\n';
  }
  for(int i=0; i<4*n; i++){
    for(int j=0; j<n; j++){
      cout << '@';
    }
    cout << '\n';
  }
  return 0;
}

