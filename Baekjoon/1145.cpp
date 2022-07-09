#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  if (a < b) return gcd(b, a);
  return gcd(b, a%b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main () {
  vector<int> nums(5);
  for(int &num: nums)
    cin >> num;
  int min_lcm = 2000000000;
  for(int i=0; i<3; i++) {
    for(int j=i+1; j<4; j++) {
      int ij_lcm = lcm(nums[i], nums[j]);
      for(int k=j+1; k<5; k++) {
        int ijk_lcm = lcm(ij_lcm, nums[k]);
        min_lcm = min(min_lcm, ijk_lcm);
      }
    }
  }
  cout << min_lcm << endl;
  return 0;
}
