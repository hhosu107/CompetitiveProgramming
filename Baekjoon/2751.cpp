#include<iostream>
#include<vector>

using namespace std;
int main(){
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> elmts = vector<int>(n, 0);
  for(int i=0; i<n; i++)
    cin >> elmts[i];
  sort(elmts.begin(), elmts.end());
  for(int i=0; i<n; i++)
    cout << elmts[i] << '\n';
  return 0;
}
