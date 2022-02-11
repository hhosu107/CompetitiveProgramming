#include<iostream>
#include<string>
using namespace std;

int main () {
  string s;
  cin >> s;
  int result = 0;
  bool minus_found = false;
  int curr_num = 0;
  for(char c: s) {
    if (c == '-' && !minus_found) {
      minus_found = true;
      result += curr_num;
      curr_num = 0;
    }
    else if (minus_found && (c == '-' || c == '+')) {
      result -= curr_num;
      curr_num = 0;
    }
    else if (c == '+') {
      result += curr_num;
      curr_num = 0;
    }
    else {
      curr_num = 10 * curr_num + (c - '0');
    }
  }
  result += (minus_found ? -curr_num : curr_num);
  cout << result << endl;
  return 0;
}
