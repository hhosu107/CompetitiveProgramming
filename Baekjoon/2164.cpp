#include<iostream>
#include<queue>

using namespace std;

int main(){
  int n;
  queue<int> cards;
  cin >> n;
  for(int i=0; i<n; i++){
    cards.push(i+1);
  }
  int counter = 0;
  while(cards.size() > 1){
    int top = cards.front();
    cards.pop();
    if (counter % 2 == 1) cards.push(top);
    counter++;
  }
  cout << cards.front() << endl;
  return 0;
}
