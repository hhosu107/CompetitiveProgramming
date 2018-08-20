#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Compare{
template <typename K, typename V>
  bool operator()(pair<K, V> lhs, pair<K, V> rhs) const {
    return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
  }
}Compare;

vector<pair<int, int>> B;
vector<pair<int, int>> Bindex;
vector<pair<int, int>> A;

int main(){
  int N;
  cin >> N;
  A = vector<pair<int, int>>(N);
  B = vector<pair<int, int>>(N);
  Bindex = vector<pair<int, int>>(N);
  for(int i=0; i<N; i++){
    cin >> A[i].first;
    A[i].second = 0;
  }
  for(int i=0; i<N; i++){
    cin >> B[i].first;
    B[i].second = i;
  }
  Bindex = B;
  sort(Bindex.begin(), Bindex.end(), Compare());
  sort(A.begin(), A.end(), Compare());
  for(int i=0; i<N; i++){
    A[N-i-1].second = Bindex[i].second;
  }
  int sum = 0;
  for(int i=0; i<N; i++)
    sum += A[i].first * B[A[i].second].first;
  cout << sum << endl;
}
