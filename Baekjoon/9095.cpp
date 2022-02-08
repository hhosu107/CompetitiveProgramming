#include<iostream>
#include<array>

using namespace std;
array<int, 11> ott;

int main () {
  int n;
  cin >> n;
  ott[1] = 1;
  ott[2] = 2;
  ott[3] = 4;
  for(int i=4; i<=10; i++)
    ott[i] = ott[i-1] + ott[i-2] + ott[i-3];
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    cout << ott[x] << endl;
  }
  return 0;
}
