#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main () {
  // If it is a multidimensional vector, max_element will work only on a last dimension.
  // Not multidimensionally.
  vector<vector<int>> twodim_vec(5, vector<int>(3));
  for(int i=0; i<5; i++) {
    for(int j=0; j<3; j++) {
      cin >> twodim_vec[i][j];
    }
  }
  cout << *max_element(twodim_vec[0].begin(), twodim_vec[0].end()) << endl;
  // Also fill works only on a last dimension.
  fill(twodim_vec[0].begin(), twodim_vec[0].end(), 0);
  // If it is an c-style array, max_element will work on every possible
  // dimension prefix.
  int twodim_arr[5][3];
  for(int i=0; i<5; i++) {
    for(int j=0; j<3; j++) {
      twodim_arr[i][j] = twodim_vec[i][j];
    }
  }
  cout << *max_element(twodim_arr[0], twodim_arr[0] + 3) << endl;
  cout << *max_element(twodim_arr, twodim_arr + 15);
  // fill works with address value.
  fill(twodim_arr[0], twodim_arr[0] + 3, -INT32_MAX);
  fill(twodim_arr, twodim_arr + 15, -INT32_MAX); // If want to use INT_MAX, import climits.
  return 0;
}
