#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
    vector<string> result;
    string token;
    stringstream ss(data);

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

int main(){
  string x = "\"a\"";
  vector<string> xx = tokenize_getline(x, '\"');
  int count = 0;
  for(string y : xx){
    cout << y << " " << count++ << endl;
  }
  string xp = "x=";
  vector<string> xxx = tokenize_getline(xp, '=');
  count = 0;
  for(string y : xxx){
    cout << y << " " << count++ << endl;
  }
}
