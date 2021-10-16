#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B. Room: coordinate plane.
 * Number of steps G needs to go from A to B = manhatten distance. (move parallel to the axes)
 * Help to find a position in the room to keep the bottle; sum of steps from the bottle to
 * "ALL" her furniture pieces will be the minimum?
 * 1. Furnitures are rectangles of nonzero area; edges are parallel.
 * 2. Furnitures can overlap.
 * 3. All furnitures doesn't block the path.
 * sol) Sum all of the functions; make them minimal; for two axes.
 * Note: if a segment is (a, b); Then when x < a; distance if a - x; a<=x<=b; distance 0; x>b: distance=b-x.
 * Thus this one can be generalized as: (|x-a| + |x-b|)/2 - (b-a).
 * Thus, minimize sum (|x-a| + |x-b|) for (a, b) in furniture.
 * Thus, sort them; find middle point of nth and n+1th point.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int K;
    cin >> K;
    vector<int> xs = vector<int>(K * 2), ys = vector<int>(K * 2);
    for(int i=0; i<K; i++){
      cin >> xs[2 * i] >> ys[2 * i] >>  xs[2 * i + 1] >> ys[2 * i + 1];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int cx = (xs[K - 1] + xs[K]) / 2;
    int cy = (ys[K - 1] + ys[K]) / 2;
    cout << "Case #" << t << ": " << cx << " " << cy << '\n';
  }
  return 0;
}
