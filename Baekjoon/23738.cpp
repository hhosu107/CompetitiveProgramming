#include<iostream>
#include<string>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string rus;
  cin >> rus;
  string rusread = "";
  for(char r: rus){
    if (r == 'B') rusread += "v";
    else if (r == 'E') rusread += "ye";
    else if (r == 'H') rusread += "n";
    else if (r == 'P') rusread += "r";
    else if (r == 'C') rusread += "s";
    else if (r == 'Y') rusread += "u";
    else if (r == 'X') rusread += "h";
    else rusread += (char)((int)r + 32);
  }
  cout << rusread << '\n';
  return 0;
}
