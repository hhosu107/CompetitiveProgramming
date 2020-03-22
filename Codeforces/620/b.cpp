#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

vector<string> strs;
vector<int> heads;
vector<int> tails;
bool catched[100];
int main(){
  int n, m;
  int wc = 0;
  cin >> n >> m;
  strs = vector<string>(n);
  heads = vector<int>();
  tails = vector<int>();
  for (int i=0; i<n; i++)
    cin >> strs[i];
  for(int i=0; i<n-1; i++){
    if (catched[i]) continue;
    string reversed(strs[i].rbegin(), strs[i].rend());
    for (int j=i+1; j<n; j++) {
      if (reversed.compare(strs[j]) == 0){
        catched[i] = catched[j] = true;
        heads.push_back(i);
        tails.push_back(j);
        wc += 2;
        break;
      }
    }
  }
  for(int i=0; i<n; i++){
    if (catched[i]) continue;
    else{
      string reversed(strs[i].rbegin(), strs[i].rend());
      if (reversed.compare(strs[i]) == 0){
        catched[i] = true;
        heads.push_back(i);
        wc += 1;
        break;
      }
    }
  }
  cout << wc * m << endl;
  for (vector<int>::iterator iter = heads.begin(); iter != heads.end(); ++iter) {
    cout << strs[*iter];
  }
  for (vector<int>::reverse_iterator iter = tails.rbegin(); iter != tails.rend(); ++iter) {
    cout << strs[*iter];
  }
  cout << endl;
  return 0;
}
