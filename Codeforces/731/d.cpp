#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

/* D. Co growing sequence
 * growing seq a1...an if for all i from 1 to n-1 all ones (of bin rep) in a_i are in the places of ones in a_i+1, i.e., a_i & a+i+1 == a_i.
 * Co growing x_1...x_n and y_1...y_n if x_i XOR y_i is growing.
 * For given x_1...x_n, find lexicographically minimal seq y_1...y_n s.t. x_i and y_i co growing.
 */
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n;
    cin >> t;
    for(int T=0; T<t; T++){
    }
    return 0;
}
