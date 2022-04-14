#include<bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
  int sum = 0;
  while(n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main () {
  vector<bool> generator(10001, false);
  for(int i=1; i<=10000; i++) {
    if (generator[i])
      continue;
    int sum = i + digit_sum(i);
    while(sum <= 10000 && !generator[sum]) {
      generator[sum] = true;
      sum = sum + digit_sum(sum);
    }
  }
  for(int i=1; i<=10000; i++)
    if (!generator[i])
      cout << i << endl;
  return 0;
}
