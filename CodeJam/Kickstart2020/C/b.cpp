#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
typedef long long ll;

/* B. Polyomino: N consecutive squares edge to edge.
 * Named from A to Z.
 * R rows C cols. Likes stable walls. Wall is stable if it can be created by adding polyominos
 * one at a time to the wall so that each polyomino is always supported. (I,e., at each step of the building process,
 * it should be stable.)
 * Supported: if each of its squares is either on the ground or has another square below it. (i.e.,
 * the wall doesn't have a hole in it.)
 * Check stability, and if it is, prove that fact by telling the order in which he added the polyominos.
 */
/* Sol)
 * Time complexity: 900^2. (since: it checks each character and find the first stable one.)
 * Lemma) If there are more than one possible step that enables stability, their order can be changed and doesn't affect on the stability.
 */
typedef pair<int, int> pii;
char wa[31][31];
class polyo{
  public:
    char name;
    int len;
    vector<pii> points;
    polyo(char _name){
      name = _name;
      len = 0;
      points = vector<pii>();
    }
    void put_pt(int y, int x){
      points.push_back(pair<int, int>(y, x));
      len++;
    }
    void sort_pts(){
      sort(points.begin(), points.end());
    }
};

bool stab(vector<vector<bool>> &occ, polyo x){
  for(pii pt: x.points){
    if (pt.first == 0 || occ[pt.first - 1][pt.second] == true){
      occ[pt.first][pt.second] = true;
    } else {
      for(pii rever: x.points){
        occ[rever.first][rever.second] = false;
      }
      return false;
    }
  }
  return true;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    vector<polyo> polyos = vector<polyo>();
    char name = 'A';
    for(int i=0; i<26; i++){
      polyos.push_back( polyo(name));
      name = (char)((int)name + 1);
    }
    int R, C;
    cin >> R >> C;
    for(int i=0; i<R; i++){
      cin >> wa[i];
      for(int j=0; j<C; j++){
        int idx = (int)wa[i][j] - (int)('A');
        polyos[idx].put_pt(R-1-i, j);
      }
    }
    for(int i=0; i<26; i++){
      if (polyos[i].len > 0){
        polyos[i].sort_pts();
      }
    }
    vector<vector<bool>> occ = vector<vector<bool>>(R, vector<bool>(C, false));
    vector<bool> used_poly = vector<bool>(26, false);
    int unused_polys = 26;
    for(int i=0; i<26; i++){
      if (polyos[i].len == 0) {
        used_poly[i] = true;
        unused_polys -= 1;
      }
    }
    vector<char> ord = vector<char>();
    bool stabil = false;
    while(unused_polys > 0){
      for(int i=0; i<26; i++){
        if (used_poly[i]) continue;
        stabil = stab(occ, polyos[i]);
        if(stabil){
          used_poly[i] = true;
          ord.push_back(polyos[i].name);
          unused_polys -= 1;
          break;
        }
      }
      if (!stabil) break;
    }
    cout << "Case #" << t << ": ";
    if (!stabil){
      cout << -1 << endl;
    } else {
      for(char o : ord){
        cout << o;
      }
      cout << endl;
    }
  }
  return 0;
}
