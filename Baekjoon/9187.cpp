#include<iostream>
using namespace std;

int weird[21][21][21];

int minima(int rule, int target){
  return (rule < target ? rule : target);
}

int main(){
  int a, b, c;
  for(int i=0; i<=20; i++){
    for(int j=0; j<=20; j++){
      for(int k=0; k<=20; k++){
        if (i == 0 || j == 0 || k == 0){
          weird[i][j][k] = 1;
        } else if (i < j && j < k) {
          weird[i][j][k] = weird[i][j][k-1] + weird[i][j-1][k-1] - weird[i][j-1][k];
        } else {
          weird[i][j][k] = weird[i-1][j-1][k] + weird[i-1][j][k-1] + weird[i-1][j][k] - weird[i-1][j-1][k-1];
        }
      }
    }
  }
  while(1) {
  cin >> a >> b >> c;
  if (a == -1 && b == -1 && c == -1) break;
  cout << "w(" << a << ", " << b << ", " << c << ") = ";
  if (a > 20 || b > 20 || c > 20){
    cout << weird[20][20][20] << endl;
  } else if (a <= 0 || b <= 0 || c <= 0){
    cout << 1 << endl;
  } else cout << weird[a][b][c] << endl;

}
  return 0;
}
