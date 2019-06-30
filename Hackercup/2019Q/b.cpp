#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

/* Colony of frogs peacefully resides in a pond, 1 alpha frog, nonnegative beta frogs.
 * Alpha studies the high art of fractions every day.
 * N lilypads in a row on the pond's surface, numbered 1 ~ N left to right, each of which is large enough to fit "at most 1" frog at a time, where A is the leftmost lilypad, and must leap its way to the rightmost lilypad before it can begin its fractions practice.
 * Initial state:
 *   A: Alpha frog, L1 = A
 *   B: Beta frog,
 *   .: Unoccupied
 * At each point in time, one of the following may occur:
 *   1) Alpha frog may leap over one or more lilypads immediately to its right which are occupied by beta frogs, and land on the next unoccupied lilpad past them, if such a lilypad exists. Alpha frog must leap over at least one Beta frog. It may not just leap to an adjacent lilypad.
 *   2) Any beta frog may leap to the next lilypad to either its left or right, if such a lilypad exists and unoccupied.
 *   3) All frogs co-operate.
 * Can Alpha frog reach to the rightmost lilypad?
 * Input: integer T, T mote lines with length-N string L.
 * Output: Y/N indicating possibility of the action.
 * 1<=T<=500, 2<=N<=5000*/
int main() {
  int T;
  cin >> T;
  cin.ignore(1, '\n');
  for (int t = 1; t <= T; t++) {
    string frogs;
    getline(cin, frogs);
    int a = 0, b = 0, n = 0;
    for (auto c : frogs) {
      switch (c) {
        case 'A':
          a++;
          break;
        case 'B':
          b++;
          break;
        case '.':
          n++;
          break;
        default:
          break;
      }
    }
    cout << "Case #" << t << ": ";
    if ((b < n && b < 2) || n == 0) {
      cout << "N\n";
    } else {
      cout << "Y\n";
    }
  }
  return 0;
}
