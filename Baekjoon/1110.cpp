#include<iostream>
using namespace std;

int count;
int pattern, cand;

int main(){
  cin >> pattern;
  cand = pattern;
  do{
    cand = 10 * (cand % 10) + (cand / 10 + cand % 10)%10;
    count++;
  }while(pattern != cand);
  cout << count << endl;
  return 0;
}
