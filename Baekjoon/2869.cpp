#include<iostream>
using namespace std;

int main() {
  int a, b, v;
  cin >> a >> b >> v;
  int recent = v - a;
  int slippery = recent / (a - b);
  if (recent % (a - b) > 0) slippery++;
  cout << slippery + 1 << endl;
  return 0;
}
