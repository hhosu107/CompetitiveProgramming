#include<iostream>
using namespace std;

int main() {
  int c;
  cin >> c;
  char x;
  if (c >= 90) x = 'A';
  else if (c >= 80) x = 'B';
  else if (c >= 70) x = 'C';
  else if (c >= 60) x = 'D';
  else x = 'F';
  cout << x << endl;
  return 0;
}
