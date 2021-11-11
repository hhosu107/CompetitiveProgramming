#include<iostream>
#include<vector>

using namespace std;

int main() {
  int h, w, n;
  int t;
  scanf("%d", &t);
  for(int i=0; i<t; i++){
    scanf("%d %d %d", &h, &w, &n);
    int floor = (n % h == 0 ? h : n % h);
    int width = ((n - 1) / h) + 1;
    printf("%d%02d\n", floor, width);
  }
  return 0;
}
