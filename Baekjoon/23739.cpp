#include<iostream>
#include<vector>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> chaps = vector<int>(n);
  for (auto& chap: chaps)
    cin >> chap;
  int rem = 30;
  int cnt = 0;
  for(auto chap: chaps){
    if (rem * 2 >= chap) cnt++;
    if (rem > chap) rem -= chap;
    else rem = 30;
  }
  cout << cnt << '\n';
  return 0;
}
