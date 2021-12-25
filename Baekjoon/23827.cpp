#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> nums = vector<ll>(n);
  ll allsum = 0L;
  for(auto& num: nums){
    cin >> num;
    allsum += num;
  }
  ll allpairprd = 0L;
  for(auto num: nums) {
    allsum -= num;
    allpairprd += (num * (allsum % 1000000007L)) % 1000000007L;
    allpairprd %= 1000000007L;
  }
  cout << allpairprd << '\n';
  return 0;
}
