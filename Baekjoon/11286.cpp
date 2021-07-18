#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct absol {
  int x = 0;
  absol(int x): x(x) {}
  bool operator<(const absol &y) const {
    int absx = (x > 0 ? x : -x);
    int absy = (y.x > 0 ? y.x : -y.x);
    return (absx == absy ? (y.x < 0 ? true : false) : (absx > absy));
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int N;
  cin >> N;
  priority_queue<absol> pq = priority_queue<absol>();
  for(int i=0; i<N; i++){
    int op;
    cin >> op;
    if (op != 0){
      pq.push(absol(op));
    } else {
      if(pq.empty()) cout << "0\n";
      else {
        cout << pq.top().x << '\n';
        pq.pop();
      }
    }
  }
  return 0;
}
