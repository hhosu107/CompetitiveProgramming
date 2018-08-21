#include<iostream>
using namespace std;
long long int N, M;
int main(){
  cin >> N >> M;
  N = N - M;
  cout << (N < 0 ? -N : N) << endl;
  return 0;
}
