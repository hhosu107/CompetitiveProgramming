#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// B. 3D print. 3 printers. Any color to print, but all 3 'D's must
// be printed in the same color.
// each printer uses 4 indiv cartrigies.
// color inc: c, m, y, k.
// Total amount of ink to print D: 10^6.
// Yellow: 10^6 y. Red: 5*10^5 magenta, 4.5*10^5 yellow, 0.5*10^5 black.
// To printk a printer must have at least the required amount of ink.
// Given the number of units of ink, output any color, defined as 4 non-neg ints
// that add up to 10^6 s.t. all three printers have enough ink to print.
// If it is impossible, print "IMPOSSIBLE".

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int c[3], m[3], y[3], k[3];
    int min_c = 1000000, min_m = 1000000, min_y = 1000000, min_k = 1000000;
    for(int i=0; i<3; i++) {
      cin >> c[i] >> m[i] >> y[i] >> k[i];
      min_c = min(min_c, c[i]);
      min_m = min(min_m, m[i]);
      min_y = min(min_y, y[i]);
      min_k = min(min_k, k[i]);
    }
    int min_sum = min_c + min_m + min_y + min_k;
    cout << "Case #" << t << ": ";
    if (min_sum < 1000000) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    min_sum = 1000000;
    cout << min(min_c, min_sum) << " ";
    min_sum -= min(min_c, min_sum);
    cout << min(min_m, min_sum) << " ";
    min_sum -= min(min_m, min_sum);
    cout << min(min_y, min_sum) << " ";
    min_sum -= min(min_y, min_sum);
    cout << min(min_k, min_sum) << "\n";
  }
  return 0;
}
