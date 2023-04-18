#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  // N pancake stacks with A_i pancakes.
  // A/B claims full stacks with alternating turns.
  // For the first turn, A choose [L_a, R_a] stack, B choose [L_b, R_b] stack.
  // In subsequent turns, each of them must choose an unclaimed stack that is
  // adjacent to a stack they claimed. If at some point there is no valid choice
  // for either player, skip that turn.
  // Game ends when every stack is claimed. Both player wants to get as many
  // pancakes. Find maximum number of pancake that alice gets.
  // Sol) If initial range doesn't collide, things get easy. If not, they will
  // try to compete between colliding area. Anyways, Bob's optimal solution is
  // choosing closest position from alice, to make no option for alice to get.
  // Thus, Alice must choose fair-at-all option.
  // 1) [L_a, ...,R_a, ..., L_b, ..., R_b]: choose R_a first.
  // 2) [L_b, ..., R_b, ..., L_a, ..., R_a]: choose L_a.
  // 3) [L_a, ..., L_b, ..., R_a, ..., R_b]: If L_b-1 selection gives larger
  // portion when A takes the whole left side, then select L_b-1. Otherwise, If
  // [0~R_a] < [R_a+1~end], choose R_a. Bob will choose R_a+1. Otherwise, choose
  // from L_b ~ R_a.
  // 4) [L_a, ..., L_b, ..., R_b, ..., R_a]: 
