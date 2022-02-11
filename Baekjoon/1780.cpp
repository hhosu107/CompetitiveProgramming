#include<iostream>
#include<array>
#include<string>

using namespace std;

array<array<int, 2187>, 2187> tile;

struct paper_count {
  int pos;
  int neut;
  int neg;
  paper_count(int p, int n, int e) : pos(p), neut(n), neg(e) {}

  paper_count operator+(const paper_count& other) {
    return paper_count(pos + other.pos, neut + other.neut, neg + other.neg);
  }

  paper_count& operator+=(const paper_count& other) {
    pos += other.pos;
    neut += other.neut;
    neg += other.neg;
    return *this;
  }

  paper_count& operator=(const paper_count& other) {
    pos = other.pos;
    neut = other.neut;
    neg = other.neg;
    return *this;
  }
};

paper_count triplet_cut(array<array<int, 2187>, 2187> &t, int x, int y, int n) {
  if (n == 1) {
    return paper_count((int)(t[x][y] == 1), (int)(t[x][y] == 0), (int)(t[x][y] == -1));
  } else {
    int a = t[x][y];
    bool zipable = true;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if (a != tile[x+i][y+j]) {
          zipable = false;
          break;
        }
      }
      if(!zipable) break;
    }
    if (zipable)
      return paper_count((int)(a == 1), (int)(a == 0), (int)(a == -1));
    else {
      paper_count sum = paper_count(0, 0, 0);
      for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
          sum = sum + triplet_cut(t, x+i*n/3, y+j*n/3, n/3);
        }
      }
      return sum;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> tile[i][j];
  }
  paper_count ans = triplet_cut(tile, 0, 0, n);
  cout << ans.neg << '\n' << ans.neut << '\n' << ans.pos << '\n';
  return 0;
}
