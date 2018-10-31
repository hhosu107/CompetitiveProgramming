#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
int N;
unordered_set<int> cache[10];
unordered_set<int> solve(int n){
  if(!cache[n].empty()) return cache[n];
  int num = 0;
  for(int i=0; i<n; i++) num = 10 * num + N;
  unordered_set<int> res;
  res.insert(num);
  for(int i=1; i<n; i++){
    int j = n-i;
    auto s1 = solve(i); // memoized
    auto s2 = solve(j); // memoized
    // fill in any possible numbers including negative ones
    for(int n1 : s1){
      for(int n2 : s2){
        res.insert(n1 + n2);
        res.insert(n1 - n2);
        res.insert(n1 * n2);
        if(n2 != 0) res.insert(n1 / n2);
      }
    }
  }
  return cache[n] = res;
}

int solution(int number){
  for(int i=1; i<=8; i++){
    solve(i);
    if(cache[i].find(number) != cache[i].end()) return i; // find a number in a set
  }
  return -1;
}

int main(){
  cin >> N;
  int n;
  cin >> n;
  int number;
  for(int i=0; i<n; i++){
    cin >> number;
    int res = solution(number);
    if(res == -1) cout << "NO\n";
    else cout << res << '\n';
  }
  return 0;
}
