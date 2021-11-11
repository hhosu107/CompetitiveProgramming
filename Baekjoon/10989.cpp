#include<iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int bucket[10001] = {0};
  int k;
  for(int i=0; i<n; i++){
    cin >> k;
    bucket[k]++;
  }
  for(int i=1; i<=10000; i++){
    for(int j=0; j<bucket[i]; j++)
      cout << i << '\n';
  }
  return 0;
}
