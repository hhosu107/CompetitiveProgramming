#include<bits/stdc++.h>

using namespace std;

unordered_set<long long> used_hash;
struct piv {
  long long hashval;
  int values[8] = {0};
  int len;
  bool operator<(const piv& other) const {
    return hashval < other.hashval;
  }
  piv () : hashval(0), len(0) {}
  piv (long long h, int a[], int l) : hashval(h), len(l){
    for (int i = 0; i < l; ++i) {
      values[i] = a[i];
    }
  }
};

vector<piv> values = vector<piv>(40320);
int counts = 0;

void print_perm(map<int, int> intcnt, int a[], int used, int maxlen) {
  if (used == maxlen) {
    long long x = 0;
    for(int i=0; i<maxlen; i++) {
      x = 10001 * x + a[i];
    }
    if(used_hash.find(x) != used_hash.end())
      return;
    piv p = piv(x, a, maxlen);
    used_hash.insert(x);
    values[counts++] = p;
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
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
  sort(values.begin(), values.begin() + counts);
  for(int i=0; i<counts; i++) {
    for(int j=0; j<values[i].len; j++) {
      cout << values[i].values[j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
