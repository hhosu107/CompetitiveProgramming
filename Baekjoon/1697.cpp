#include<iostream>
#include<array>
#include<queue>

using namespace std;
array<int, 100001> reaching_count;

int main () {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  q.push(n);
  while(n != k && reaching_count[k] == 0) {
    int cur = q.front();
    q.pop();
    if (cur > 0 && reaching_count[cur - 1] == 0) {
      q.push(cur - 1);
      reaching_count[cur - 1] = reaching_count[cur] + 1;
    }
    if (cur < 100000 && reaching_count[cur + 1] == 0) {
      q.push(cur + 1);
      reaching_count[cur + 1] = reaching_count[cur] + 1;
    }
    if (cur <= 50000 && reaching_count[cur * 2] == 0) {
      q.push(cur * 2);
      reaching_count[cur * 2] = reaching_count[cur] + 1;
    }
  }
  cout << reaching_count[k] << endl;
  return 0;
}
