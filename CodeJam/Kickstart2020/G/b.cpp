#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  long long int T;
  cin >> T;
  for(long long int t = 1; t<=T; t++){
    long long int N, val;
    cin >> N;
    vector<long long int> diag = vector<long long int>(2 * N + 1, 0);
    for(long long int i=0; i<N; i++){
      for(long long int j=0; j<N; j++){
        cin >> val;
        diag[j-i+N] += val;
      }
    }
    long long int max = -1;
    for(long long int i=1; i<=2*N; i++){
      if (max < diag[i]) max = diag[i];
    }
    cout << "Case #" << t << ": " << max << endl;
  }
  return 0;
}
