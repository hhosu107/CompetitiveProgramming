#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n;
  vector<int> cards = vector<int>(n);
  map<int, int> card_count = map<int, int>();
  for(auto& card: cards)
    cin >> card;
  cin >> m;
  vector<int> findings = vector<int>(m);
  for(auto& finding: findings)
    cin >> finding;
  for(auto card: cards){
    auto elmt = card_count.find(card);
    if (elmt != card_count.end()) {
      card_count[card] = card_count[card] += 1;
    } else {
      card_count[card] = 1;
    }
  }
  for(auto finding: findings) {
    auto elmt = card_count.find(finding);
    if (elmt == card_count.end()) {
      cout << "0 ";
    } else {
      cout << card_count[elmt->first] << " ";
    }
  }
  cout << '\n';
  return 0;
}
