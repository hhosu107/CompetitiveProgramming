#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
pii maxmin(vector<int> &a, int idx, int len, int curr, vector<int>& remain){
  if(idx + 1 == len) return pii(curr, curr);
  else {
    pii locmm (-2147483648, 2147483647);
    for(int i=0; i<4; i++){
      if(remain[i] > 0){
        int nextcurr = curr;
        remain[i] -= 1;
        if (i == 0) nextcurr = curr + a[idx + 1];
        else if (i == 1) nextcurr = curr - a[idx + 1];
        else if (i == 2) nextcurr = curr * a[idx + 1];
        else if (i == 3) nextcurr = curr / a[idx + 1];
        pii subres = maxmin(a, idx + 1, len, nextcurr, remain);
        remain[i] += 1;
        if (subres.first > locmm.first) locmm.first = subres.first;
        if (subres.second < locmm.second) locmm.second = subres.second;
      }
    }
    return locmm;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a = vector<int>(n, 0);
  vector<int> remain = vector<int>(4, 0);
  for(int i=0; i<n; i++)
    cin >> a[i];
  for(int i=0; i<4; i++)
    cin >> remain[i];
  pii result = maxmin(a, 0, n, a[0], remain);
  cout << result.first << endl << result.second << endl;
  return 0;
}
