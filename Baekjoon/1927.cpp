#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    if (x == 0) {
      cout << (min_heap.size() > 0 ? min_heap.top() : 0) << '\n';
      if (min_heap.size() > 0) min_heap.pop();
    }
    else {
      min_heap.push(x);
    }
  }
  return 0;
}
