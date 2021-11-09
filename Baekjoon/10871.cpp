#include<iostream>
#include<vector>

using namespace std;

int main () {
  int n, x;
  cin >> n >> x;
  vector<int> smaller = vector<int>();
  int cand;
  for(int i=0; i<n; i++){
    cin >> cand;
    if (cand < x) smaller.push_back(cand);
  }
  for (int c : smaller)
    cout << c << " ";
  cout << endl;
  return 0;
}
