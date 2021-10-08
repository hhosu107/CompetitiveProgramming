#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;
struct members {
  int age;
  string name;
  int order;

  members(int age, string name, int order) : age(age), name(name), order(order) {}

  bool operator<(const members &otherm) const {
    return (age > otherm.age) || (age == otherm.age && (order > otherm.order));
  }
};

vector<vector<int>> perms(vector<int> curr, int len, int m, int n){
  if (len == m) {
    return vector<vector<int>>(1, curr);
  } else {
    vector<vector<int>> result = vector<vector<int>>(0, vector<int>());
    int leftcap = (len == 0 ? 0 : curr[len - 1]);
    for(int next = 1; next <= n; next++){
      vector<int> nextcurr (curr);
      bool keep = true;
      for(int i=0; i<len; i++){
        if (curr[i] == next) { keep = false; break;}
      }
      if(!keep) continue;
      nextcurr.push_back(next);
      vector<vector<int>> curr_result = perms(nextcurr, len + 1, m, n);
      result.insert(result.end(), curr_result.begin(), curr_result.end());
    }
    return result;
  }
}

int main(){
  int N;
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  priority_queue<members> mems = priority_queue<members>();
  for(int i=0; i<N; i++){
    int age;
    string name;
    cin >> age >> name;
    members x {age, name, i};
    mems.push(x);
  }
  while(!mems.empty()) {
    cout << mems.top().age << " " << mems.top().name << '\n';
    mems.pop();
  }
  return 0;
}
