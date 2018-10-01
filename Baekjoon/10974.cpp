#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

vector<int> perm;
int main(){
    int n;
    cin >> n;
    perm = vector<int>(n);
    for(int i=0; i<n; i++)
        perm[i] = i+1;
    do{
      for(int elmt : perm){
        cout << elmt << " ";
      } cout << endl;
      int firstRev = -1;
      for(int i=n-2; i>=0; i--){
          if(perm[i] < perm[i+1]){
              firstRev = i;
              break;
          }
      }
      if(firstRev == -1) break;
      else{
          int pivot = perm[firstRev];
          int leastUpper = n+1;
          int leastUpperIndex = firstRev;
          for(int i=n-1; i>firstRev; i--){
              if(leastUpper > perm[i] && perm[i] > pivot){
                  leastUpper = perm[i];
                  leastUpperIndex = i;
              }
          }
          iter_swap(perm.begin() + firstRev, perm.begin() + leastUpperIndex);
          sort(perm.begin() + firstRev + 1, perm.end());
      }
    }while(1);
    return 0;
}
