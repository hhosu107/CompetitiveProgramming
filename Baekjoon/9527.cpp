#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
  ll a, b;
  cin >> a >> b;
  a -= 1;
  ll bb = b, aa = a;
  ll b1sum = 0, a1sum = 0;
  ll bbase = 1, abase = 1;
  for(int i=0; i<64 && bb > 0; i++) {
    b1sum += (bb / 2) * bbase;
    b1sum += max(((b % (bbase * 2)) - bbase) + 1, 0LL);
    bb /= 2;
    bbase *= 2;
  }
  for(int i=0; i<64 && aa > 0; i++) {
    a1sum += (aa / 2) * abase;
    a1sum += max(((a % (abase * 2)) - abase) + 1, 0LL);
    aa /= 2;
    abase *= 2;
  }
  cout << b1sum - a1sum << endl;
  return 0;
  /*
  vector<ll> twop(64, 1);
  for(int i=1; i<64; i++)
    twop[i] = twop[i-1] * 2LL;
  vector<int> da(64, 0), ra(64, 0), db(64, 0), rb(64, 0), ab(64, 0), bb(64, 0);
  ll ta = a, tb = b;
  for(int i=0; i<64; i++) {
    ab[i] = (ta >> i) % 2;
    bb[i] = (tb >> i) % 2;
    da[i] = (ta / twop[i]);
    ra[i] = (ta % twop[i]);
    db[i] = (tb / twop[i]);
    rb[i] = (tb % twop[i]);
  }
  ll onesum = 0;
  for(int i=0; i<64 && da[i] + db[i] > 0; i++) {
    if (da[i] == db[i]) {
      if (ab[i] == 1) {
        onesum += (rb[i] - ra[i] + 1);
      }
      continue;
    } else {
      ll a_inc = (ra[i] == 0 ? 0 : twop[i] - ra[i]);
      if (ab[i] == 1) {
        onesum += a_inc;
      }
      ll da_inc = (ra[i] == 0 ? da[i] : da[i] + 1);
      ll b_dec = rb[i];
      ll db_dec = db[i];
      if (bb[i] == 1) {
        onesum += b_dec + 1;
      }
      ll one_included_parts = 0;
      if ((db_dec - da_inc) % 2 == 0 || da_inc % 2 == 0) {
        one_included_parts = (db_dec - da_inc) / 2;
      } else {
        one_included_parts = (db_dec - da_inc) / 2 + 1;
      }
      onesum += one_included_parts * twop[i];
    }
  }
  cout << onesum << '\n';
  return 0;
  */
}
