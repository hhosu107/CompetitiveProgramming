#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n;
    int ints[200];
    cin >> t;
    for(int T=0; T<t; T++){
        cin >> n;
        int oddcnt = 0;
        int curr;
        for(int i=0; i<2*n; i++){
            cin >> curr;
            if(curr % 2 == 1) oddcnt++;
        }
        if (oddcnt * 2 == n) cout << "Yes\n";
        else cout << "No\n";    
    }
    return 0;
}