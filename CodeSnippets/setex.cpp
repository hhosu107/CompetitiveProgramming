#include<iostream>
#include<set>
#include<iterator>

using namespace std;

set<int> se;

int main(){
  se.insert(3);
  se.insert(4);
  se.insert(2);
  auto x = se.find(3);
  auto y = prev(x, 1);
  auto z = next(x, 1);
  cout << *x << " " << *y << " " << *z << endl;
  se.erase(5);
  return 0;
}
