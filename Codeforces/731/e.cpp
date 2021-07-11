#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<unordered_map>

using namespace std;

/* E. In length n array, there are k air conditioners located in a_i for i.
 * Each air conditioner is characterized by temperature.
 * For each cell i; find its temperature min{j in [1..k](t_j + |a_j - i|)}.
 *
 * Sol) Make a mountain.
 */

struct airc{
  int loc=0, temp=0;

  airc(int l=0, int t=0) : loc(l), temp(t) {}
  void operator=(const airc &right) {
    loc = right.loc;
    temp = right.temp;
  }
  bool operator<(const airc &right) const {
    return loc < right.loc;
  }
  bool operator==(const airc &right) const {
    return (loc == right.loc && temp == right.temp);
  }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n, k;
    cin >> t;
    for(int T=0; T<t; T++){
      cin >> n >> k;
      vector<airc> conds = vector<airc>(k);
      vector<int> locs = vector<int>(k);
      vector<int> temps = vector<int>(k);
      int loc, temp;
      for(int i=0; i<k; i++)
        cin >> locs[i];
      for(int i=0; i<k; i++)
        cin >> temps[i];
      for(int i=0; i<k; i++){
        conds[i] = airc(locs[i], temps[i]);
      }
      sort(conds.begin(), conds.end());
      vector<airc> valids = vector<airc>(k, airc(0, 0));
      valids[0] = conds[0];
      int vl = 1;
      for(int i=1; i<k; i++){
        while(vl > 0){
          if ((conds[i].loc - valids[vl-1].loc) + conds[i].temp <= valids[vl-1].temp){
            vl--;
          } else break;
        }
        valids[vl++] = conds[i];
      }
      int currcon = 0;
      for(int i=1; i<=n; i++){
        if (valids[currcon].loc >= i){
          cout << valids[currcon].temp + (valids[currcon].loc - i) << " ";
        } else {
          if (currcon == vl - 1)
            cout << valids[currcon].temp + (i - valids[currcon].loc) << " ";
          else {
            int currt = valids[currcon].temp + (i - valids[currcon].loc);
            int nextt = valids[currcon + 1].temp + (valids[currcon + 1].loc - i);
            if (nextt <= currt){
              cout << nextt << " ";
              currcon++;
            } else {
              cout << currt << " ";
            }
          }
        }
      }
      cout << "\n";
    }
    return 0;
}
