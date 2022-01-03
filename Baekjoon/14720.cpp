#include<iostream>
#include<array>

using namespace std;

using ll = long long;

template<typename T, int n>
using arr = array<T, n>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  int x;
  int milk = 0;
  int currmilk = 0;
  for (int i=0; i<n; i++){
    cin >> x;
    if (currmilk == x) {
      milk++;
      currmilk = (currmilk + 1) % 3;
    }
  }
  cout << milk << '\n';
  return 0;
}
