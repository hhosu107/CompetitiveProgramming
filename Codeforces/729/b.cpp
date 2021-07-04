#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;
/* B. Inf set:
1 in set
if x in set, x * a, x + b in set
given a, b, n, determine if n in the set.
*/
typedef long long int ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int T;
    long long int a, b, n;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> a >> b;
        priority_queue<ll, vector<ll>, greater<ll>> pq = priority_queue<ll, vector<ll>, greater<ll>>();
        pq.push(1);
        bool flag = false;
        while(pq.top() <= n){
            int top = pq.top();
            if (top == n){
                flag = true;
                break;
            }
            pq.push(top + b);
            pq.push(top * a);
            pq.pop();
        }
        cout << (flag ? "Yes" : "No") << "\n";
    }
    return 0;
}