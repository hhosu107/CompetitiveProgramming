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
        cin >> perm[i];
    int firstRev = -1;
    for(int i=n-2; i>=0; i--){
        if(perm[i] > perm[i+1]){
            firstRev = i;
            break;
        }
    }
    if(firstRev != -1){
        int pivot = perm[firstRev];
        int mostLower = 0;
        int mostLowerIndex = firstRev;
        for(int i=n-1; i>firstRev; i--){
            if(mostLower < perm[i] && perm[i] < pivot){
                mostLower = perm[i];
                mostLowerIndex = i;
            }
        }
        iter_swap(perm.begin() + firstRev, perm.begin() + mostLowerIndex);
        sort(perm.begin() + firstRev + 1, perm.end(), greater<int>());
        for(int elmt : perm){
            cout << elmt << " ";
        }
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}
