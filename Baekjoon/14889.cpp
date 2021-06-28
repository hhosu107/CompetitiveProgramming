#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int statdiff(vector<vector<int>> crossstat, int n, vector<int> &lefts, vector<int> &rights, int sumleft, int sumright, int pleft, int pright){
  if (pleft == (n / 2) && pright == (n / 2)){
    return (sumleft > sumright ? sumleft - sumright : sumright - sumleft);
  }
  int mindiff = 2147483647;
  if (pleft < (n / 2)){
    int currleft = sumleft;
    for(int i=0; i<pleft; i++){
      currleft += (crossstat[lefts[i]][pleft + pright] + crossstat[pleft + pright][lefts[i]]);
    }
    lefts[pleft] = pleft + pright;
    int currdiff = statdiff(crossstat, n, lefts, rights, currleft, sumright, pleft + 1, pright);
    if (mindiff > currdiff) mindiff = currdiff;
  }
  if (pright < (n / 2)){
    int currright = sumright;
    for(int i=0; i<pright; i++){
      currright += (crossstat[rights[i]][pleft + pright] + crossstat[pleft + pright][rights[i]]);
    }
    rights[pright] = pleft + pright;
    int currdiff = statdiff(crossstat, n, lefts, rights, sumleft, currright, pleft, pright + 1);
    if (mindiff > currdiff) mindiff = currdiff;
  }

  return mindiff;
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> crossstat = vector<vector<int>>(n, vector<int>(n, 0));
  vector<int> lefts = vector<int>(n/2, 0);
  vector<int> rights = vector<int>(n/2, 0);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
    cin >> crossstat[i][j];
  }
  int mindiff = statdiff(crossstat, n, lefts, rights, 0, 0, 0, 0);
  cout << mindiff << endl;
  return 0;
}
