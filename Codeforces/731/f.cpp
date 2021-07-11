#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
/* F. Array stabilization (GCD version)
 * a = [a0, ..., an-1]
 * In one step, a is replaced with length n array, [gcd(a_0, a_1), ..., gcd(a_n-1, a_0)].
 * Find steps to make that array a constant array.
 * If all initial elements were identical, then print 0.
 * Sol) At step k, The array should be [gcd(a_0, ..., a_k), ..., gcd(a_n-1, a_0, ..., a_k-1)].
 * Our goal is: When the kth step equals to the nth step.
 */

int abss(int a, int b){
  return (a > b ? a - b : b - a);
}

int gcd(int a, int b){
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n;
    cin >> t;
    for(int T=0; T<t; T++){
      cin >> n;
      vector<int> values = vector<int>(n, 0);
      for(int i=0; i<n; i++)
        cin >> values[i];
      vector<bool> don = vector<bool>(n, false);
      int donecnt = 0;
      int glob = values[0];
      for(int i=1; i<n; i++){
        glob = gcd(glob, values[i]);
      }
      for(int i=0; i<n; i++){
        if(values[i] == glob){
          don[i] = true;
          donecnt++;
        }
      }
      int loopcnt = 0;
      vector<int> gcds(values.begin(), values.end());
      while(donecnt < n){
        loopcnt++;
        for(int i=0; i<n; i++){
          if (don[i]) continue;
          gcds[i] = gcd(values[(i + loopcnt) % n], gcds[i]);
          if (gcds[i] == glob){
            don[i] = true;
            donecnt++;
          }
        }
      }
      cout << loopcnt << endl;
    }
    return 0;
}
