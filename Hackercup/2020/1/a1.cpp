#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

typedef long long ll;
const ll univmod = 1000000007L;
using namespace std;

class UpperSeg{
public:
  UpperSeg(ll _l, ll _h, ll _len):
    l{_l}, h{_h}, len{_len} {}
  ll l;
  ll h;
  ll len;
};

/* A. N rectangular rooms. Rooms: 2-dim plane with axis aligned walls,
 * southen wall of each room has y-coord 0.
 * ith rectangular room: (L_i, 0) / (L_i + W, H_i).
 * In A1, W's are equal and L_i increases stritly.
 * These rooms may overlap with one another.
 * Keep houses warm and energy efficient. First, gather perimeters around
 * various combinations of rooms.
 * Let P_i the perimeter of rooms 1~i. Compute product(1<=i<=N)P_i mod 10^9+7.
 * For each case, K/L_1~L_K/H_1~H_K will be given, and for L_K+1~N/H_K+1~N,
 * You will compute that with (A_L, B_L, C_L, D_L)  (A_H, B_H, C_H, D_H) so that
 * L_i = ((A_L * L_i-2 + B_L * L_i-1 + C_L) mod D_L) + 1 for i > K,
 * H_i = ((A_H * H_i-2 + B_H * H_i-1 + C_H) mod D_H) + 1 for i > K.
 */
int main(){
  int T, N, K;
  ll W;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int t=1; t<=T; t++){
    int ls[4], hs[4];
    cin >> N >> K >> W;
    vector<ll> L = vector<ll>(N, 0L);
    vector<ll> H = vector<ll>(N, 0L);
    for(int i=0; i<K; i++){
      cin >> L[i];
    }
    cin >> ls[0] >> ls[1] >> ls[2] >> ls[3];
    for(int i=0; i<K; i++){
      cin >> H[i];
    }
    cin >> hs[0] >> hs[1] >> hs[2] >> hs[3];
    vector<ll> perm = vector<ll>(N, 0L);
    vector<ll> permprod = vector<ll>(N, 0L);
    vector<UpperSeg> upper_pts = vector<UpperSeg>(N, UpperSeg(0L, 0L, 0L));
    permprod[0] = perm[0] = (2 * W + 2 * H[0]) % univmod;
    upper_pts[0] = UpperSeg(L[0], H[0], W);
    int up_rm = 1;
    for(int i=K; i<N; i++){
      L[i] = (((ls[0] * L[i-2] + ls[1] * L[i-1] + ls[2]) % ls[3]) + 1);
      H[i] = (((hs[0] * H[i-2] + hs[1] * H[i-1] + hs[2]) % hs[3]) + 1);
    }
    for(int i=1; i<N; i++){
      if (L[i] - L[i-1] > W) {
        perm[i] = (perm[i-1] + 2 * W + 2 * H[i]) % univmod;
        upper_pts[up_rm++] = UpperSeg(L[i], H[i], W);
      } else {
        int j = up_rm - 1;
        ll dl = L[i] - L[i-1];
        ll dh = 0;
        for (; j >= 0 && upper_pts[j].l + W >= L[i]; j--){
          if (upper_pts[j].h < H[i]) {
            dh = H[i] - upper_pts[j].h;
            upper_pts[j] = UpperSeg(0L, 0L, 0L);
            up_rm--;
          } else {
            upper_pts[up_rm++] = UpperSeg(L[i], H[i], L[i] - upper_pts[j].l);
            perm[i] = (perm[i-1] + 2 * dl) % univmod;
            break;
          }
        }
        if (perm[i] == 0){
          upper_pts[up_rm++] = UpperSeg(L[i], H[i], W);
          perm[i] = (perm[i-1] + 2 * dl + 2 * dh) % univmod;
        }
      }
      permprod[i] = (permprod[i-1] * perm[i]) % univmod;
    }
    cout << "Case #" << t << ": " << permprod[N-1] << endl;
  }
  return 0;
}
