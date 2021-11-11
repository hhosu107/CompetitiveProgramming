#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<int> nums = vector<int>(n);
  vector<int> buckets = vector<int>(8001);
  int sum = 0;
  for(int i=0; i<n; i++){
    cin >> nums[i];
    sum += nums[i];
    buckets[nums[i] + 4000]++;
  }
  vector<int> mostoftenvalues = vector<int>();
  int occ = 0;
  for(int i=-4000; i<=4000; i++){
    if (buckets[i+4000] > occ) {
      occ = buckets[i+4000];
      mostoftenvalues = vector<int>();
      mostoftenvalues.push_back(i);
    } else if (buckets[i+4000] == occ){
      mostoftenvalues.push_back(i);
    }
  }
  sort(nums.begin(), nums.end());
  int center = nums[n/2];
  int range = nums[n-1] - nums[0];
  long double avg = (double)(sum) / (double)(n);
  int avg_round = (int)round(avg);
  int occval = mostoftenvalues[0];
  if (mostoftenvalues.size() >= 2){
    occval = mostoftenvalues[1];
  }
  cout << avg_round << '\n' << center << '\n' << occval << '\n' << range << '\n';
  return 0;
}
