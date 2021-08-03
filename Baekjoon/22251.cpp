#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

int stoother[10][10];
long long int flips(int digit, int maxdigit, int currval, int max, vector<int> &orig, int flip, int maxflip){
  if (digit == maxdigit){
    if (flip == 0 || flip > maxflip || currval == 0 || currval > max) return 0L;
    return 1L;
  }
  long long int validFlips = 0;
  for(int i=0; i<10; i++){
    long long currFlips = flips(digit + 1, maxdigit, currval * 10 + i, max, orig, flip + stoother[orig[digit]][i], maxflip);
    validFlips += currFlips;
  }
  return validFlips;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  vector<vector<int>> sls = vector<vector<int>>(10, vector<int>(7));
  sls[0] = vector<int>({1, 1, 1, 0, 1, 1, 1});
  sls[1] = vector<int>({0, 0, 1, 0, 0, 1, 0});
  sls[2] = vector<int>({1, 0, 1, 1, 1, 0, 1});
  sls[3] = vector<int>({1, 0, 1, 1, 0, 1, 1});
  sls[4] = vector<int>({0, 1, 1, 1, 0, 1, 0});
  sls[5] = vector<int>({1, 1, 0, 1, 0, 1, 1});
  sls[6] = vector<int>({1, 1, 0, 1, 1, 1, 1});
  sls[7] = vector<int>({1, 0, 1, 0, 0, 1, 0});
  sls[8] = vector<int>({1, 1, 1, 1, 1, 1, 1});
  sls[9] = vector<int>({1, 1, 1, 1, 0, 1, 1});
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      stoother[i][j] = 0;
      for(int k=0; k<7; k++){
        stoother[i][j] += (sls[i][k] + sls[j][k]) % 2;
      }
    }
  }
  int n, k, p, x;
  cin >> n >> k >> p >> x;
  vector<int> xseg = vector<int>(k);
  int xx = x;
  for(int i=k-1; i>=0; i--){
    xseg[i] = xx % 10;
    xx /= 10;
  }
  long long int cnt = flips(0, k, 0, n, xseg, 0, p);
  cout << cnt << '\n';
  return 0;
}
