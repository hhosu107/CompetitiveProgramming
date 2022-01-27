#include<iostream>
using namespace std;

int main () {
  long long int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (a > b) {
    swap(a, b);
  }
  long long int xsign = 1;
  if (x == 0) {
    if (a <= y && y <= b) {
      cout << y << endl;
    } else cout << "Unknwon Number" << endl;
    return 0;
  }
  else if (x < 0) {
    xsign = -1;
    x = -x;
    y = (y == 0 ? 0 : x - y);
    a = -a;
    b = -b;
    swap(a, b);
  }
  long long int lefty = (a - y) / x;
  long long int leftr = (a - y) % x;
  long long int righty = (b - y) / x;
  long long int rightr = (b - y) % x;
  if (leftr < 0) {
    lefty--;
    leftr += x;
  }
  if (rightr < 0) {
    righty--;
    rightr += x;
  }
  if (lefty == righty) {
    if (leftr == 0) {
      cout << xsign * (lefty * x + y) << endl;
    } else if (rightr == 0) {
      cout << xsign * (righty * x + y) << endl;
    } else cout << "Unknwon Number" << endl;
  } else if (lefty + 1 == righty) {
    if (leftr < rightr || (leftr == rightr && leftr == 0)) {
      cout << "Unknwon Number" << endl;
    } else cout << xsign * (righty * x + y) << endl;
  } else cout << "Unknwon Number" << endl;
  return 0;
}


