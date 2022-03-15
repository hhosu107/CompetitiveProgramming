#include<bits/stdc++.h>

using namespace std;

struct val_try {
  int val;
  int trial;

  val_try() : val(0), trial(0) {}
  val_try(int v, int t) : val(v), trial(t) {}
  bool operator<(const val_try &other) const {
    return val > other.val || (val == other.val && trial > other.trial);
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> coins (n);
  for(int i=0; i<n; i++) {
    cin >> coins[i];
  }
  int k;
  cin >> k;
  vector<int> num_trials (coins[n-1] * k + 1, k + 1);
  num_trials[0] = 0;
  priority_queue<val_try> pq; // < follows the larger one; thus minheap.
  pq.push({0, 0});
  int found_val = 0;
  int broken = false;
  while(!pq.empty()) {
    val_try cur = pq.top();
    pq.pop();
    if (cur.val > 1 && cur.val > found_val + 1) {
      broken = true;
      found_val += 1;
      break;
    }
    found_val = cur.val;
    if (cur.trial == k) {
      continue;
    }
    for (int i=0; i<n; i++) {
      if (num_trials[cur.val + coins[i]] <= cur.trial + 1) continue;
      num_trials[cur.val + coins[i]] = cur.trial + 1;
      pq.push({cur.val + coins[i], cur.trial + 1});
    }
  }
  if (!broken) {
    broken = true;
    found_val += 1;
  }
  cout << (found_val % 2 == 0 ? "holsoon " : "jjaksoon ") << "win at " << found_val << '\n';
  return 0;
}
