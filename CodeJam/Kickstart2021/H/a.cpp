#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
 * A. String S; a padlock, lowercase english. String F, a favorite lowercases.
 * Perform several ops on the padlock. Change one letter of the string to the
 * one following it / one proceeding it.
 * Find min. number of operations to convert S to F.
 * Sol) sum Min(up/down).
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  string s;
  string f;
  for (int t=1; t<=T; t++){
    cin >> s >> f;
    int rot = 0;
    for (char c : s) {
      int closest = 26;
      for (char t : f) {
        int diff = (c < t ? (int)(t - 'a') - (int)(c - 'a') : (int)(c - 'a') - (int)(t - 'a'));
        int near = (diff > 13 ? 26 - diff : diff);
        closest = (closest < near ? closest : near);
      }
      rot += closest;
    }
    cout << "Case #" << t << ": " << rot << endl;
  }

  return 0;
}
