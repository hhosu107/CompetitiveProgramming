#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main () {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int N;
    cin >> N;
    map<string, int> clothes;
    string name, part;
    for(int i=0; i<N; i++){
      cin >> name >> part;
      if(clothes.find(part) == clothes.end()) {
        clothes[part] = 1;
      }
      else clothes[part]++;
    }
    int counts = 1;
    // Answer: product(1 + clothes[part]) - 1. (we select not to wear a part or
    // select a part among k different kinds. Iterate for each part, and finally
    // exclude when a person is naked.)
    for(auto it: clothes)
      counts *= (clothes[it.first] + 1);
    cout << counts - 1 << '\n';
  }
  return 0;
}
