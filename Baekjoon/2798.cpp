#include<iostream>
using namespace std;

int main(){
  int N, M;
  int black[100];
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> black[i];
  }
  int max = 0;
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      for(int k=j+1; k<N; k++){
        if (max < black[i] + black[j] + black[k] && black[i] + black[j] + black[k] <= M) max = black[i] + black[j] + black[k];
      }
    }
  }
  cout << max << endl;
}
