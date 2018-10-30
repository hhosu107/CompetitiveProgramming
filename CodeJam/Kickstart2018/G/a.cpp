#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long int arr[200];

int main(){
  ios::sync_with_stdio(false);
  int T, N;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    int cnt = 0;
    for(int i=0; i<N; i++)
      cin >> arr[i];
    for(int i=0; i<N-2; i++){
      for(int j=i+1; j<N-1; j++){
        for(int k=j+1; k<N; k++){
          if(arr[i]*arr[j] == arr[k] || arr[j]*arr[k] == arr[i] || arr[k]*arr[i] == arr[j]) cnt++;
        }
      }
    }
    cout << "Case #" << t << ": " << cnt << '\n';
  }
  return 0;
}
