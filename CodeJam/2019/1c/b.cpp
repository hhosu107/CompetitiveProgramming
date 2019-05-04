#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
  int T, F;
  cin >> T >> F;
  bool failed = false;
  for(int t=1; t<=T; t++){
    string ans;
    bool af=false, bf=false, cf=false, df=false, ef=false;
    // 1st wave (try 1, 6, ...)
    vector<int> a, b, c, d, e;
    for(int i=0; i<119; i++){
      char ch;
      cout << i*5 + 1 << endl;
      cout.flush();
      cin >> ch;
      if(ch == 'A') a.push_back(i*5+1);
      if(ch == 'B') b.push_back(i*5+1);
      if(ch == 'C') c.push_back(i*5+1);
      if(ch == 'D') d.push_back(i*5+1);
      if(ch == 'E') e.push_back(i*5+1);
    }
    vector<int> nextPool;
    if(a.size() == 23) {
      ans += 'A';
      af = true;
      nextPool = a;
    }
    if(b.size() == 23) {
      ans += 'B';
      bf = true;
      nextPool = b;
    }
    if(c.size() == 23) {
      ans += 'C';
      cf = true;
      nextPool = c;
    }
    if(d.size() == 23) {
      ans += 'D';
      df = true;
      nextPool = d;
    }
    if(e.size() == 23) {
      ans += 'E';
      ef = true;
      nextPool = e;
    }
    // 2nd wave (find the missing one, and try to find the next missing one when excluding the first missing one - fix it as the first character)
    vector<int> a2, b2, c2, d2, e2;
    for(int i=0; i<23; i++){
      char ch;
      cout << nextPool[i] + 1 << endl;
      cout.flush();
      cin >> ch;
      if(ch == 'A') a2.push_back(nextPool[i]+1);
      if(ch == 'B') b2.push_back(nextPool[i]+1);
      if(ch == 'C') c2.push_back(nextPool[i]+1);
      if(ch == 'D') d2.push_back(nextPool[i]+1);
      if(ch == 'E') e2.push_back(nextPool[i]+1);
    }
    vector<int> nextPool2;
    if(a2.size() == 5) {
      ans += 'A';
      af = true;
      nextPool2 = a2;
    }
    if(b2.size() == 5) {
      ans += 'B';
      bf = true;
      nextPool2 = b2;
    }
    if(c2.size() == 5) {
      ans += 'C';
      cf = true;
      nextPool2 = c2;
    }
    if(d2.size() == 5) {
      ans += 'D';
      df = true;
      nextPool2 = d2;
    }
    if(e2.size() == 5) {
      ans += 'E';
      ef = true;
      nextPool2 = e2;
    }
    // 3rd wave (same)
    vector<int> a3, b3, c3, d3, e3;
    for(int i=0; i<5; i++){
      char ch;
      cout << nextPool2[i]+1 << endl;
      cout.flush();
      cin >> ch;
      if(ch == 'A') a3.push_back(nextPool2[i]+1);
      if(ch == 'B') b3.push_back(nextPool2[i]+1);
      if(ch == 'C') c3.push_back(nextPool2[i]+1);
      if(ch == 'D') d3.push_back(nextPool2[i]+1);
      if(ch == 'E') e3.push_back(nextPool2[i]+1);
    }
    vector<int> nextPool3;
    if(a3.size() == 1) {
      ans += 'A';
      af = true;
      nextPool3 = a3;
    }
    if(b3.size() == 1) {
      ans += 'B';
      bf = true;
      nextPool3 = b3;
    }
    if(c3.size() == 1) {
      ans += 'C';
      cf = true;
      nextPool3 = c3;
    }
    if(d3.size() == 1) {
      ans += 'D';
      df = true;
      nextPool3 = d3;
    }
    if(e3.size() == 1) {
      ans += 'E';
      ef = true;
      nextPool3 = e3;
    }
    // 4th wave (same)
    vector<int> a4, b4, c4, d4, e4;
    for(int i=0; i<1; i++){
      char ch;
      cout << nextPool3[i]+1 << endl;
      cout.flush();
      cin >> ch;
      if(ch == 'A') a4.push_back(nextPool3[i]+1);
      if(ch == 'B') b4.push_back(nextPool3[i]+1);
      if(ch == 'C') c4.push_back(nextPool3[i]+1);
      if(ch == 'D') d4.push_back(nextPool3[i]+1);
      if(ch == 'E') e4.push_back(nextPool3[i]+1);
    }
    if(a4.size() == 0 && af == false) {
      ans += 'A';
      af = true;
    }
    if(b4.size() == 0 && bf == false) {
      ans += 'B';
      bf = true;
    }
    if(c4.size() == 0 && cf == false) {
      ans += 'C';
      cf = true;
    }
    if(d4.size() == 0 && df == false) {
      ans += 'D';
      df = true;
    }
    if(e4.size() == 0 && ef == false) {
      ans += 'E';
      ef = true;
    }
    // what's remaining?
    if (!af) {
      ans += 'A';
    }
    else if(!bf) {
      ans += 'B';
    }
    else if (!cf) {
      ans += 'C';
    }
    else if (!df) {
      ans += 'D';
    }
    else if(!ef) {
      ans += 'E';
    }
    cout << ans << endl;
    cout.flush();
    string judge;
    cin >> judge;
    if(judge.compare("Y") != 0){
      failed = true;
      break;
    }
  }
  return 0;
}
