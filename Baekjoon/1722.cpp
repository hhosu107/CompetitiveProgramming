#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

bool used[21];
vector<long long int> coef;
vector<int> perm;
int main(){
    int n;
    long long int k=0, order=0;
    cin >> n;
    perm = vector<int>(n+1);
    cin >> k;
    coef = vector<long long int>(n+1);
    coef[0] = 0;
    coef[1] = 1;
    for(int i=2; i<=n; i++){
      coef[i] = coef[i-1] * (i-1);
    }
    if(k == 1){
      cin >> order;
      for(int i=n; i>=1; i--){
        for(int index = 1; index <= n; index++){
          if(used[index] == true) continue;
          else if(order > coef[i]){
            order -= coef[i];
          }
          else{
            perm[n+1-i] = index;
            used[index] = true;
            break;
          }
        }
      }
      for(int i=1; i<=n; i++){
        cout << perm[i] << " ";
      }
      cout << endl;
    }
    else{
      for(int i=1; i<=n; i++)
        cin >> perm[i];
      for(int i=n; i>=1; i--){
        int unused = 0;
        for(int index=1; index<perm[n+1-i]; index++){
          if(used[index] == true) continue;
          else unused++;
        }
        used[perm[n+1-i]] = true;
        order += unused * coef[i];
      }
      order++;
      cout << order << endl;
    }
    return 0;
}

