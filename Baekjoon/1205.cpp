// Need to fix.
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n, np, p;
  cin >> n >> np >> p;
  vector<int> scores = vector<int>(n);
  for(int i=0; i<n; i++)
    cin >> scores[i];
  if (n == 0) cout << 1 << endl;
  else {
    int rank = n + 1;
    for(int i=0; i<n; i++){
      if (scores[i] < np) {
        rank = i + 1;
        break;
      }
    }
    if (rank <= p) cout << rank << endl;
    else cout << -1 << endl;
  }
  return 0;
}
