#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// A. Feed with D portions of dog food, C portions of cat food.
/* N animals: dogs/cats.
 * String S consistring of C and D: order of cats and dogs.
 * Each dog eats 1 portion of dog food; vice versa for cat.
 * Every time a DOG eats food, bring M extra portions of cat food.
 * Ordered feeding: an animal can only eat if the animal before it has already eaten.
 * If one of the food portions is ran out, the line will never be shorten.
 * Determine if in this scenario all the DOGS in the line will be fed.
 * If fed, "YES"; o.w., "NO"
 */

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  long long int N, D, C, M;
  string s;
  for (int t=1; t<=T; t++){
    cin >> N >> D >> C >> M;
    cin >> s;
    long long int remd = D, remc = C;
    bool flag = true;
    int i=0;
    while (i < N) {
      if (s[i] == 'C'){
        if (remc == 0){
          bool nodog = true;
          for(int j=i+1; j<N; j++){
            if (s[j] == 'D'){
              nodog = false;
              flag = false;
              break;
            }
          }
          break;
        } else {
          remc--;
          i++;
        }
      } else {
        if (remd == 0){
          flag = false;
          break;
        } else {
          remd--;
          remc += M;
          i++;
        }
      }
    }
    cout << "Case #" << t << ": ";
    if (!flag) cout << "NO\n";
    else cout << "YES\n";   
  }

  return 0;
}
