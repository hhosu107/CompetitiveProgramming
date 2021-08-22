#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B. Birthday Cake
 * R*C columns. 1~R rows, 1~C columns, grid 1*1.
 * Most delicious part forms a single rectangle, i.e., delicious in a single rectangle, not delicious in others.
 * Knife that is long enought to make straight-line cuts of length up to K.
 * Make a series of cuts to extract each of the delicious cells separately, put candles, enjoy.
 * Must be disconnected from any other cell.
 * Valid cut:
 * Cut runs along one of the horizontal/vertical lines btwn rows/coluns.
 * Length <=K
 * starting/ending polong long ints: grid polong long ints. Starting polong long int must be already exposed; 4 sides of the grid or one of the prev cuts.
 * Cut must NOT pass thru any other exposed polong long ints. Touching is accepted, but end right there.
 * Find min number of cuts needed to extract all the delicious cells.
 * Sol) First, extract 4 sides of the rectangular. If we make a cut that crosses the delicious area before we extract, then we have to cut at least 2 times to extract that sides, which makes things bother.
 * How to compute? - compute the shortest distance from the border of the cake to the delicious part. Then we have to cut ceiling(D/K) times. After that, cut other sides. If other side is the subset of the cake edge, do nothing to cut, otherwise, cut Ceiling(R_D / K) for row cut, Ceiling(C_D / K) for col cut.
 * After extracting, do division following this rule:
 * Cut as K*K sized square as possible.
 * We get at most 4 types of rectangle: K*K, K*R, C*K, C*R.
 * With binary cut, compute optimal number of cuts. K*K-1, K*R-1, C*K-1, C*R-1.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  long long int T;
  cin >> T;
  for (long long int t=1; t<=T; t++){
    long long int R, C, K;
    long long int r1, c1, r2, c2;
    cin >> R >> C >> K >> r1 >> c1 >> r2 >> c2;
    // Extract outside of delicious part
    bool upattach = false, downattach = false, leftattach = false, rightattach = false;
    if (r1 == 1) upattach = true;
    if (c1 == 1) leftattach = true;
    if (r2 == R) downattach = true;
    if (c2 == C) rightattach = true;
    long long int cuts = 0;
    if (!(upattach || downattach || leftattach || rightattach)) {
      long long int mincut = 100000;
      long long int dist = r1 - 1;
      long long int cut = (dist + (K - 1)) / K;
      if (cut < mincut) mincut = cut;
      dist = R - r2;
      cut = (dist + (K - 1)) / K;
      if (cut < mincut) mincut = cut;
      dist = c1 - 1;
      cut = (dist + (K - 1)) / K;
      if (cut < mincut) mincut = cut;
      dist = C - c2;
      cut = (dist + (K - 1)) / K;
      if (cut < mincut) mincut = cut;
      cuts = mincut;
    }
    if (!upattach) cuts += (c2 - c1 + 1 + (K - 1)) / K;
    if (!downattach) cuts += (c2 - c1 + 1 + (K - 1)) / K;
    if (!leftattach) cuts += (r2 - r1 + 1 + (K - 1)) / K;
    if (!rightattach) cuts += (r1 - r1 + 1 + (K - 1)) / K;
    // Extract by K * K.
    long long int rows = r2 - r1 + 1;
    long long int cols = c2 - c1 + 1;
    /* Suppose ceil(rows / K) = RP.
     * Then with rows / RP, we can express rows as sum of RP numbers:
     * ceil(rows / RP) * (rows % RP) + floor(rows / RP) * (RP - rows % RP).
     * vice versa for (cols / K).
     */
    long long int rowDivK = rows / K;
    long long int rremDivK = rows % K;
    long long int colDivK = cols / K;
    long long int cremDivK = cols % K;
    long long int rowUnits = rowDivK + (rremDivK > 0 ? 1 : 0);
    long long int colUnits = colDivK + (cremDivK > 0 ? 1 : 0);
    cuts += (rowUnits - 1) * colUnits + (colUnits - 1) * rowUnits;
    long long int rowsDomCount = (rows % rowUnits > 0 ? rows % rowUnits : rowUnits);
    long long int colsDomCount = (cols % colUnits > 0 ? cols % colUnits : colUnits);
    // Number of segments with length ceil(rows / rowDivK): rowsDomCount if rowDomCount > 0; rowDivK if rowDonCount = 0.
    // Number of segments with length floor(rows / rowDivK): rowDivK - rowsDomCount if rowDomCount > 0; 0 o.w.
    // Vice versa for others.
    cuts += (rowsDomCount * colsDomCount) * (((rows + (rowUnits - 1)) / (rowUnits)) * ((cols + (rowUnits - 1)) / colUnits) - 1);
    cuts += (rowUnits - rowsDomCount) * colsDomCount * ((rows / rowUnits) * ((cols + (colUnits - 1)) / colUnits) - 1);
    cuts += rowsDomCount * (colUnits - colsDomCount) * (((rows + (rowUnits - 1) / rowUnits)) * (cols / colUnits) - 1);
    cuts += (rowUnits - rowsDomCount) * (colUnits - colsDomCount) * ((rows / rowUnits) * (cols / colUnits) - 1);
    // Cut each K * K, K * cremDivK, rremDivK * K, rremDivK * cremDivK.
    // K * K: (rowUnits - 1) * (colUnits - 1)
    /*
    cuts += (rowUnits - 1) * (colUnits - 1) * (K * K - 1);
    // K * cremDivK: (rowUnits - 1)
    if (cremDivK > 0){
      cuts += (rowUnits - 1) * (cremDivK * K - 1);
    }
    // rremDivK * K: (colUnits - 1)
    if (rremDivK > 0){
      cuts += (colUnits - 1) * (rremDivK * K - 1);
    }
    // rremDivK * cremDivK: 1
    if (cremDivK > 0 && rremDivK > 0){
      cuts += (cremDivK * rremDivK - 1);
    }
    */
    cout << "Case #" << t << ": " << cuts << '\n';
  }
  return 0;
}
