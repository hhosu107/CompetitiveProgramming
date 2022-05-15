#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

/* Other idea:
 * jewel도, bag도 각각 weight 가벼운 것 순, capacity 작은 것 순으로 정렬한다.
 * priority_queue에 무게 가벼운 순서대로 jewel의 "가치"를 담는데, 이 때
 * 현재 보고 있는 가방에 들어갈 수 있는 무게의 jewel만 넣는다. 넣을 수 없게 되는
 * 첫 번째 jewel을 발견하면, 넣는 걸 중단하고 (index 올리지 않고),
 * heap에 들어있는 jewel 중 가장 무거운 jewel을 가방에 할당한다.
 * 그리고 남아있는 jewel들과, 다음 jewel들의 합 (다음 가방에 들어갈 수 있는
 * 것들까지만) 중에서 가장 무거운 jewel을 그 다음 가방에 할당한다. (이미
 * 들어있던 jewel들은 더 capacity가 큰 가방에 여전히 들어갈 수 있으므로)
 * 그러면 모든 가방이 감당 가능한 가장 비싼 jewel을 챙기므로 answer.
 * 참고로, 만약 pq가 비었는데 다음 보석이 가방의 capacity보다 무거운 경우, 그
 * 가방을 스킵하는 것이 옳다는 것을 보여야 한다.
 * 일반성을 잃지 않고 직전 가방까지 꽉 차 있었다고 하자. 그러면 그 앞의 가방들은
 * 이미 최적의 방법으로 전부 채웠기 때문에, 지금의 가방을 비우는 것이 맞다 (더
 * capacity가 큰 가방을 비울 필요가 없다)
 */
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<pll> jewels(n, make_pair(0, 0));
  vector<ll> c(k, 0);
  for(int i=0; i<n; i++)
    cin >> jewels[i].first >> jewels[i].second;
  for(int i=0; i<k; i++)
    cin >> c[i];
  sort(jewels.begin(), jewels.end());
  sort(c.begin(), c.end());
  int curr_jewel = 0;
  ll sum = 0;
  priority_queue<ll> pq;
  for(int i=0; i<k; i++) {
    while(curr_jewel < n && jewels[curr_jewel].first <= c[i]) {
      pq.push(jewels[curr_jewel].second);
      curr_jewel++;
    }
    if (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }
  cout << sum << '\n';
  return 0;
}

