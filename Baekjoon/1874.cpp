#include<iostream>
#include<vector>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq = vector<int>(n);
  for(auto& s: seq)
    cin >> s;
  vector<int> val = vector<int>(n);
  int head = 0;
  int enteredVal = 0;
  int currval = 0;
  vector<char> ops = vector<char>(2 * n);
  int opshead = 0;
  for(int i=0; i<n; i++){
    if (enteredVal < seq[i]) {
      for(int j=enteredVal+1; j<=seq[i]; j++){
        val[head++] = j;
        ops[opshead++] = '+';
      }
      head--;
      val[head] = 0;
      enteredVal = seq[i];
      ops[opshead++] = '-';
    } else {
      while(head > 0 && seq[i] >= val[head-1]) {
        head--;
        val[head] = 0;
        ops[opshead++] = '-';
      }
    }
  }
  for(int i=0; i<2*n; i++)
    cout << ops[i] << '\n';
  return 0;
}
