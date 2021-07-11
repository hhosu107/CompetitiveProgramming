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

// If the iterator points a struct, use x->attribute.
// For set of structs, construct a comparator in the struct as:
/*
   struct cmpByDist {
   bool operator()(const Type& l, const Type& r) const {
       return compareMetric;
   }
}
*/
// Use this as operator<. If you consider this as operator>, then set_instance.begin() will return the largest one.
