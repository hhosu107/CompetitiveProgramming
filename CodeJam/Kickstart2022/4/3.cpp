#include<bits/stdc++.h>

using namespace std;

/* 3. N ants, stick with L cm, drop ants on it.
 * ant i: dropped at P_i. Each ant travels to left/right with 1cm.
 * Initial directions: D_i. 0: left, 1: right.
 * ant bounce off, and fall off the stick.
 * Find exact order in which the ants fall off the stick.
 * Sol) Let there be two ants a and b. a is placed on the left, b right.
 * Suppose they are menacing each other. Then they will meet at x = (a+b) / 2.
 * If (a + b) / 2 < l/2, then a will fall off the first. Otherwise, b will fall
 * off the first. WLoG, suppose l - a < b. Then b will fall first.
 * Suppose they move in the same direction. If both moves left, a will fall
 * first. Otherwise, b will fall first.
 * In summary, 1. we save ants on the deque with increasing order of the position.
 * When the position is smaller, it will be placed in the left side of the
 * deque.
 * In each step, the front/back will fall and be removed from the deque.
 * 2. Next we save the distance of ants regarding of their direction.
 */
using pii = pair<int, int>;
using vpi = vector<pii>;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T, n;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int pos, id, dir;
    int n, l;
    cin >> n >> l;
    vector<int> fall_order(n);
    vpi ants(n); // This saves the distance from each ant to the end of the stick. Compare with 0 if direction is left, l if direction is right.
    for(int i=0; i<n; i++) {
      cin >> pos >> dir;
      dir = 2 * dir - 1; // -1 if left, 0 if right;
      ants[i] = make_pair(pos, (i + 1) * dir); // Save ant's id with direction. Smaller id will fall first if two ants fall in the same timestamp.
    }
    sort(ants.begin(), ants.end());
    // We save ant's id with the order of original distance.
    deque<int> ant_id; // On the deque, the front means the first leftmost ant that may fall into the left / the back means the first rightmost ant that may fall into the right.
    for(int i=0; i<n; i++) {
      ant_id.push_back(ants[i].second);
    }
    for(int i=0; i<n; i++) {
      if (ants[i].second > 0)
        ants[i].first = l - ants[i].first;
    }
    sort(ants.begin(), ants.end()); // Sort by distance from the end of the stick.
    int fallen_ants = 0;
    for(int i=0; i<n; i++) {
      int front_ant = ant_id.front(), back_ant = ant_id.back();
      if (i != n - 1 && ants[i].first == ants[i + 1].first) { // Not the last ant, and the both of the ant will fall in the same time; we have to decide their order.
        if (abs(front_ant) < abs(back_ant)) {
          fall_order[fallen_ants++] = abs(front_ant);
          fall_order[fallen_ants++] = abs(back_ant);
        } else {
          fall_order[fallen_ants++] = abs(back_ant);
          fall_order[fallen_ants++] = abs(front_ant);
        }
        ant_id.pop_back();
        ant_id.pop_front();
        i++; // Both of ants are fallen.
      } else {
        if (ants[i].second < 0) { // No matter what distance that ants[i+1] has, ants[i] will fall first to the left side (proof: if ants[i+1]'s direction is left, ants[i] falls first. if ants[i+1]'s direction is right, still the distance to the right is larger that ants[i], so ants[i] fall first.
          fall_order[fallen_ants++] = abs(front_ant);
          ant_id.pop_front();
        } else { // It will fall to the right side.
          fall_order[fallen_ants++] = abs(back_ant); // In this case, ants[i+1]'s direction was left. If it was right, then it cannt be longer that ants[i]'s length. Finally, if it was left, when ants[i] and ants[i+1] coincides (virtually), the meet point is tillted to the right side of the stick. (ex: 13 1 / 18 0: meets at 15.5 and then turns back. When they turns back, the right ant will fall first.
          ant_id.pop_back();
        }
      }
    }
    cout << "Case #" << t << ": ";
    for(int i=0; i<n; i++) {
      cout << fall_order[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
