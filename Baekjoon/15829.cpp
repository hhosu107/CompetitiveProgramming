#include<iostream>
#include<string>

using namespace std;

int main() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  int r = 31;
  int m = 1234567891;
  long long sum = 0L;
  for(int i=n-1; i>=0; i--){
    sum = (31L * sum + ((int)(s[i] - 'a') + 1)) % m;
  }
  cout << sum << endl;
  return 0;
}
