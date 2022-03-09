#include<iostream>
#include<vector>

long long int sfibo[120];

using namespace std;

int main(){
  int n;
  cin >> n;
  sfibo[1] = sfibo[2] = sfibo[3] = 1;
  for (int i=4; i<=n; i++)
    sfibo[i] = sfibo[i-1] + sfibo[i-3];
  cout << sfibo[n] << endl;
  return 0;
}
