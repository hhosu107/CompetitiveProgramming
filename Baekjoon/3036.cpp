#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for_each(a.begin(), a.end(), [&](int &x) { cin >> x; });
  for(int i=1; i<n; i++) {
    int g = gcd(a[0], a[i]);
    cout << a[0] / g << "/" << a[i] / g << endl;
  }
  return 0;
}
