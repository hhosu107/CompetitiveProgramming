#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  int sum = 0;
  cin >> n;
  vector<int> prices = vector<int>(n);
  int head = 0;
  int val = 0;
  for(int i=0; i<n; i++){
    cin >> val;
    if(val == 0){
      head--;
    } else prices[head++] = val;
  }
  for(int i=0; i<head; i++)
    sum += prices[i];
  cout << sum << endl;
  return 0;
}
