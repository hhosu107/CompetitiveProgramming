#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct wifi {
  int str;
  int x;
  int y;
  wifi() : str(0), x(0), y(0) {}
  wifi(int str, int x, int y): str(str), x(x), y(y) {}
};

int rempow(const wifi& orig, const wifi& loc) {
  return max(0, (orig.str - abs(orig.x - loc.x) - abs(orig.y - loc.y)));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<wifi> wifis = vector<wifi>(n+1);
  for(auto& w: wifis)
    cin >> w.x >> w.y >> w.str;
  int max = 0;
  for(int i=1; i<=n; i++){
    int orig = rempow(wifis[0], wifis[i]);
    for(int j=1; j<=n; j++){
      if(wifis[j].str > 0){
        int rem = rempow(wifis[j], wifis[i]);
        orig -= rem;
        if (orig <= 0) break;
      }
    }
    if (max < orig) max = orig;
  }
  if (max == 0) cout << "IMPOSSIBLE\n";
  else cout << max << '\n';
  return 0;
}
