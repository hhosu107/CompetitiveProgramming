#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<string>

using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  string methods;
  int n;
  cin >> T;
  for(int t=0; t<T; t++){
    cin >> methods >> n;
    string num_values;
    cin >> num_values;
    num_values = num_values.substr(1, num_values.size() - 2);
    vector<string> nums = split(num_values, ',');
    deque<int> deq = deque<int>();
    for(auto num: nums)
      deq.push_back(stoi(num));
    bool head_pick = true;
    bool error = false;
    for(auto op: methods){
      if (op == 'D') {
        if (deq.empty()) {
          error = true;
          break;
        } else {
          if (head_pick) deq.pop_front();
          else deq.pop_back();
        }
      } else if (op == 'R') {
        head_pick = !head_pick;
      }
    }
    if (error) cout << "error\n";
    else {
      cout << '[';
      while(!deq.empty()) {
        int top = (head_pick ? deq.front() : deq.back());
        cout << top;
        (head_pick ? deq.pop_front() : deq.pop_back());
        if (deq.empty()) break;
        else cout << ',';
      }
      cout << "]\n";
    }
  }
  return 0;
}
