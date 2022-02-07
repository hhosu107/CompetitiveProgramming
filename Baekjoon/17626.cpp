#include<iostream>
using namespace std;

int num_square[50001];

int num_squares(int n, int remain_count) {
  if (n == 0) return 0;
  if (num_square[n] != 999) return num_square[n];
  else if (remain_count == 0) {
    return 999;
  }
  else {
    int min = 999;
    for(int i=1; i*i<=n; i++) {
      int temp = num_squares(n - i*i, remain_count - 1);
      if (temp < min) {
        min = temp;
      }
    }
    num_square[n] = min + 1;
    return num_square[n];
  }
}

int main () {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    num_square[i] = 999;
  }
  cout << num_squares(n, 4) << endl;
  return 0;
}
