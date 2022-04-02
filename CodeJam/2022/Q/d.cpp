#include<bits/stdc++.h>
using namespace std;

// D. Modules that are not pointed at by any others: initiators.
// Only initiator can be activated manually.
// When a module is triggered, it triggers that points it.
// Triggering continues until the chain would hit the abyss or an already
// triggered module. This is chain reaction.
// Each of the N modules hass a fun factor F_i.
// Fun = largest fun factor that triggered in that reaction.
// Wile will activate each initiator once, in some order.
// sum of fun = sum of fun he gets from each chain reaction.
// Ex) 4 -> 2 -> 1 -> abyss, 3 -> 1 -> abyss.
// if 4->2 = 50, 2->1 = 20, 1->abysss = 60, 3->1 = 40,
// If 4 is activated first, 4->2->1 activates, and getts max(50, 20, 60) = 60.
// And then 3 activation makes 40.
// If 3 is activated first, 3->1->abyss activates, and gets max(40, 60) = 60.
// And then 4 activates, which gets max(50, 20) = 50.
// This is the maximum.
// Given the fun factors and the setup, compute the maximum fun.
int main () {
  int T, N;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}
