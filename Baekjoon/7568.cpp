#include<iostream>
using namespace std;

int main(){
  int n;
  int x[50], y[50];
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> x[i] >> y[i];
  int more[50] = {0};
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if (x[i] < x[j] && y[i] < y[j]) more[i]++;
    }
    cout << more[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
