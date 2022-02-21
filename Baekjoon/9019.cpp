/* noj.am/9019
 * Idea: bfs, backtracking path to reveal. */
#include<bits/stdc++.h>

using namespace std;

struct node {
  int before;
  int current;
  string reached_op;

  node(int b, int c, string r) : before(b), current(c), reached_op(r) {}
  node() : before(0), current(0), reached_op("") {}
  node& operator=(const node& n) {
    before = n.before;
    current = n.current;
    reached_op = n.reached_op;
    return *this;
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int b, a;
    cin >> a >> b;
    array<node, 10000> mark = {};
    array<bool, 10000> visited = {};
    queue<node> q;
    q.push(node(a, a, ""));
    visited[a] = true;
    mark[a] = node(a, a, "");
    while(!q.empty()) {
      node cur = q.front();
      if (cur.current == b) {
        break;
      }
      q.pop();
      if (!visited[(cur.current + 10000 - 1) % 10000]) {
        mark[(cur.current + 10000 - 1) % 10000] = node(cur.current, (cur.current + 10000 - 1) % 10000, "S");
        q.push(node(cur.current, (cur.current + 10000 - 1) % 10000, "S"));
        visited[(cur.current + 10000 - 1) % 10000] = true;
      }
      if (!visited[(cur.current * 2) % 10000]) {
        mark[(cur.current * 2) % 10000] = node(cur.current, (cur.current * 2) % 10000, "D");
        q.push(node(cur.current, (cur.current * 2) % 10000, "D"));
        visited[(cur.current * 2) % 10000] = true;
      }
      if (!visited[(cur.current / 1000) + (cur.current - (cur.current / 1000) * 1000) * 10]) {
        mark[(cur.current / 1000) + (cur.current - (cur.current / 1000) * 1000) * 10] = node(cur.current, (cur.current / 1000) + (cur.current - (cur.current / 1000) * 1000) * 10, "L");
        q.push(node(cur.current, (cur.current / 1000) + (cur.current - (cur.current / 1000) * 1000) * 10, "L"));
        visited[cur.current / 1000 + (cur.current - (cur.current / 1000) * 1000) * 10] = true;
      }
      if (!visited[(cur.current / 10) + (cur.current % 10) * 1000]) {
        mark[cur.current / 10 + (cur.current % 10) * 1000] = node(cur.current, (cur.current / 10 + (cur.current % 10) * 1000), "R");
        q.push(node(cur.current, (cur.current / 10 + (cur.current % 10) * 1000), "R"));
        visited[(cur.current / 10) + (cur.current % 10) * 1000] = true;
      }
    }
    string ops = "";
    int c = b;
    while(c != a) {
      ops = mark[c].reached_op + ops;
      c = mark[c].before;
    }
    cout << ops << '\n';
  }
  return 0;
}
