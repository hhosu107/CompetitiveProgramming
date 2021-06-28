#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int statdiff(vector<vector<int>> &crossstat, int n, vector<int> &lefts, vector<int> &rights,
    int sumleft, int sumright, int pleft, int pright){
  if (pleft == (n / 2) && pright == (n / 2)){
    return (sumleft > sumright ? sumleft - sumright : sumright - sumleft);
  }
  int statdiff = 2147483647;
  if (pleft < (n / 2)){
    int currleft = sumleft;
    for(int i=0; i<pleft; i++){
      currleft += (crossstat[lefts[i]][pleft + pright] + crossstat[pleft + pright][lefts[i]]);
    }
    lefts[pleft] = pleft + pright;
    int currdiff = statdiff(crossstat, n, lefts, rights, currleft, sumright, pleft + 1, pright);
    if (statdiff > currdiff) statdiff = currdiff;
  }
  if (pright < (n / 2)){
    int currright = sumright;
    for(int i=0; i<pright; i++){
      currright += (crossstat[rights[i]][pleft + pright] + crossstat[pleft + pright][rights[i]]);
    }
    rights[pleft] = pleft + pright;
    int currdiff = statdiff(crossstat, n, lefts, rights, sumleft, currright, pleft, pright + 1);
    if (statdiff > currdiff) statdiff = currdiff;
  }

  return 0;
}

int main(){
  return 0;
}
