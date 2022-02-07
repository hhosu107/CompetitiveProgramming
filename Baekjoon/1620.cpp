#include<unordered_map>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main () {
  int n, q;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> q;
  unordered_map<string, string> name_id;
  vector<string> id_name = vector<string>(n + 1);
  for(int i=1; i<=n; i++){
    string s;
    cin >> s;
    name_id[s] = to_string(i);
    id_name[i] = s;
  }
  for(int i=0; i<q; i++){
    string s;
    cin >> s;
    if (name_id.find(s) != name_id.end()){
      cout << name_id[s] << '\n';
    }
    else cout << id_name[stoi(s)] << '\n';
  }
  return 0;
}
