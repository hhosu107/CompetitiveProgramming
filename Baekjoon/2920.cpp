#include<iostream>
#include<string>
using namespace std;

int main() {
  int a[8];
  for(int i=0; i<8; i++)
    cin >> a[i];
  int diff = a[1] - a[0];
  string res;
  if (diff == 1) res.assign("ascending");
  else if (diff == -1) res.assign("descending");
  else res.assign("mixed");
  for(int i=1; i<7; i++){
    if (a[i + 1] - a[i] != diff) {
      res.assign("mixed");
      break;
    }
  }
  cout << res << endl;
  return 0;
}
