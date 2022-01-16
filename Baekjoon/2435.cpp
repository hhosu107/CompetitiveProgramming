#include<iostream>

using namespace std;
int temp[100];

int main() {
  int n, k;
  cin >> n >> k;
  int ksum[101] = {0};
  int maxksum = -99999999;
  int len = 0;
  for(int i=0; i<n; i++){
    cin >> temp[i];
    ksum[i+1] = ksum[i] + temp[i] - (len < k ? 0 : temp[i-k]);
    len = (len < k ? len + 1 : k);
    maxksum = (len == k ? (maxksum < ksum[i+1] ? ksum[i+1] : maxksum) : maxksum);
  }
  cout << maxksum << endl;
  return 0;
}
