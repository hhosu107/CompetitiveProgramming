#include<iostream>
#include<array>
#include<queue>

using namespace std;
array<int, 100001> reaching_count;

/* 0-1 BFS. When the two vertices are connected with 0-weight edge,
 * when a vertex u is visited, all the vertices that can be reached from it
 * with 0-weight edge are marked as visited.
 * These vertices must be searched right after the vertex u is visited.
 * With deque, we update the front of the queue, and immidiately search the
 * front of the queue to do the search of the same-leveled vertices.
 * Reference: https://justicehui.github.io/medium-algorithm/2018/08/30/01BFS/
 */
int main () {
  int n, k;
  cin >> n >> k;
  if (k <= n) {
    cout << n - k << endl;
    return 0;
  }
  for(int i=0; i<=100000; i++)
    reaching_count[i] = -1;
  deque<int> q;
  q.push_back(n);
  reaching_count[n] = 0;
  int cur = q.front();
  while(cur != k && reaching_count[k] == -1) {
    q.pop_front();
    if (cur <= 50000 && cur > 0 && reaching_count[cur * 2] == -1) {
      q.push_front(cur * 2);
      reaching_count[cur * 2] = reaching_count[cur];
    }
    if (cur > 0 && reaching_count[cur - 1] == -1) {
      q.push_back(cur - 1);
      reaching_count[cur - 1] = reaching_count[cur] + 1;
    }
    if (cur < 100000 && reaching_count[cur + 1] == -1) {
      q.push_back(cur + 1);
      reaching_count[cur + 1] = reaching_count[cur] + 1;
    }
    cur = q.front();
  }
  cout << reaching_count[k] << endl;
  return 0;
}
