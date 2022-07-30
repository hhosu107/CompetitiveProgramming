#include<istream>
#include<ostream>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int main () {
  vector<int> vec;
  copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec));
  copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
}
