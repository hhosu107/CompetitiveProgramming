#include<bits/stdc++.h>

using namespace std;

unordered_set<long long> used_hash;

void print_perm(map<int, int> intcnt, int a[], int used, int maxlen) {
  if (used == maxlen) {
    long long x = 0;
    for(int i=0; i<maxlen; i++) {
      x = 10001 * x + a[i];
    }
    if(used_hash.find(x) != used_hash.end())
      return;
    for(int i=0; i<maxlen; i++) {
      cout << a[i] << " ";
      used_hash.insert(x);
    }
    cout << '\n';
    return;
  }
  for(auto it=intcnt.begin(); it!=intcnt.end(); it++) {
    if(it->second == 0) continue;
    it->second--;
    a[used] = it->first;
    print_perm(intcnt, a, used + 1, maxlen);
    a[used] = 0;
    print_perm(intcnt, a, used, maxlen);
    it->second++;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> intcnt;
  int num;
  for(int i=0; i<n; i++){
    cin >> num;
    if (intcnt.find(num) == intcnt.end())
      intcnt[num] = 1;
    else intcnt[num]++;
  }
  auto it = intcnt.begin();
  int a[8] = {0};
  print_perm(intcnt, a, 0, m);
  return 0;
}
