#include<array>
#include<iostream>

// array example
using namespace std;

using mat=array<array<int, 50>, 50>; // array cannot accept variable as its dimension unless it is templatized.
// Still templatized doesn't mean that you can generate array with dynamic
// dimension. It only means that when the templated function accepts array, it
// can accept various shaped ones.

template<typename T, size_t n, size_t m>
int count_nonempty(array<array<T, n>, m> &arr) {
  int cnt = 0;
  for(auto row: arr) {
    for(auto col: row) {
      if (col != 0) cnt++;
    }
  }
  return cnt;
}

int main() {
    array<array<int, 5>, 3> arr1{}; // empty initialization can be done like this
    array<array<int, 2>, 3> arr2{{1, 2, 0, 0, 3, 4}}; // nonempty initialization can be done like this
    array<array<int, 3>, 2> arr3{{1, 3, 5}}; // partial initialization can be done like this; filled from the front
    array<array<int, 3>, 3> arr4{{{1}, {2}, {0, 1}}}; // initialization has been done columnwise partially.
    cout << count_nonempty(arr1) << count_nonempty(arr2) << count_nonempty(arr3) << count_nonempty(arr4) << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            cout << arr4[i][j];
        }
    }
    return 0;
}
