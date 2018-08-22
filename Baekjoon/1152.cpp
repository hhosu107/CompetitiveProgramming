#include<string>
#include<algorithm>
#include<functional>
#include<cctype>
#include<iostream>
using namespace std;

inline unsigned count(const string& s){
  string x = s;
  replace_if(x.begin(), x.end(), ptr_fun <int, int> (isspace), ' ');
  x.erase(0, x.find_first_not_of(" "));
  if(x.empty()) return 0;
  return count(x.begin(), unique(x.begin(), x.end()), ' ') + !isspace(*s.rbegin());
}

int main(){
  string s;
  getline(cin, s);
  cout << count(s) << endl;
  return 0;
}
