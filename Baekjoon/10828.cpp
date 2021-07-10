#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<limits>  // To use cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
using namespace std;

typedef long unsigned int sizet;
int main(){
  int n;
  string cmd;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<int> stack = vector<int>(n, 0);
  int top_ptr = 0;
  for(int i=0; i<n; i++){
    getline(cin, cmd);
    sizet prev = 0, curr;
    curr = cmd.find(' ');
    if (curr == string::npos){
      if(cmd.compare("pop") == 0){
        if (top_ptr > 0){
          cout << stack[top_ptr - 1] << endl;
          top_ptr--;
        } else cout << -1 << endl;
      } else if (cmd.compare("size") == 0){
        cout << top_ptr << endl;
      } else if (cmd.compare("empty") == 0){
        cout << (top_ptr > 0 ? 0 : 1) << endl;
      } else if (cmd.compare("top") == 0){
        cout << (top_ptr > 0 ? stack[top_ptr - 1] : -1) << endl;
      }
    } else {
      int elmt = 0;
      prev = curr + 1;
      curr = cmd.find(' ', prev);
      std::stringstream ssInt(cmd.substr(prev, curr - prev));
      ssInt >> elmt;
      if (!ssInt.fail())
        stack[top_ptr++] = elmt;
    }
  }
  return 0;
}

