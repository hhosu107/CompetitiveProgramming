#include<iostream>
#include<string>
using namespace std;

int main() {
  int alphas[26];
  for(int i=0; i<26; i++)
    alphas[i] = -1;
  string s;
  cin >> s;
  int x = 0;
  for(char c : s){
    alphas[(int)(c - 'a')] = (alphas[(int)(c - 'a')] != -1 ? alphas[(int)(c - 'a')] : x);
    x++;
  }
  for(int i=0; i<26; i++)
    cout << alphas[i] << " ";
  cout << endl;
  return 0;
}
