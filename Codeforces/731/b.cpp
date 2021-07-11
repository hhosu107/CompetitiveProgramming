#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    string target;
    cin >> t;
    for(int T=0; T<t; T++){
      cin >> target;
      int length = target.length();
      int left = 0, right = length - 1;
      bool flag = true;
      while(left <= right){
        char l = target[left], r = target[right];
        if (l == (char)((int)('a') + (right - left))) {
          left++;
        }
        else if (r == (char)((int)('a') + (right - left))) {
          right--;
        } else {
          flag = false;
          break;
        }
      }
      if (flag) cout << "YES\n";
      else cout << "NO\n";
    }
    return 0;
}
