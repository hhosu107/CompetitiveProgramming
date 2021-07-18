#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int M;
  cin >> M;
  vector<int> b(M);
  for(int i=0; i<M; i++)
      cin >> b[i];
  for(int i=0; i<M; i++){
    int lo = 0, hi = N - 1;
    bool flag = false;
    while(lo < hi){
      int mid = (lo + hi) / 2;
      if (a[mid] == b[i]){
        cout << "1\n";
        flag = true;
        break;
      } else if (a[mid] < b[i]){
        lo = mid + 1;
      } else hi = mid - 1;
    }
    if (!flag){
      if (a[lo] == b[i]){
        cout << "1\n";
      } else cout << "0\n";
    }
  }
  return 0;
}
