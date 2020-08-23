#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

/* A. N rectangular rooms. Rooms: 2-dim plane with axis aligned walls,
 * southen wall of each room has y-coord 0.
 * ith rectangular room: (L_i, 0) / (L_i + W, H_i).
 * In A1, W's are equal and L_i increases stritly.
 * These rooms may overlap with one another.
 * Keep houses warm and energy efficient. First, gather perimeters around
 * various combinations of rooms.
 * Let P_i the perimeter of rooms 1~i. Compute product(1<=i<=N)P_i.
 * For each case, K/L_1~L_K/H_1~H_K will be given, and for L_K+1~N/H_K+1~N,
 * You will compute that with (A_L, B_L, C_L, D_L)  (A_H, B_H, C_H, D_H) so that
 * L_i = ((A_L * L_i-2 + B_L * L_i-1 + C_L) mod D_L) + 1 for i > K,
 * H_i = ((A_H * H_i-2 + B_H * H_i-1 + C_H) mod D_H) + 1 for i > K.
 */
int main(){
  return 0;
}
