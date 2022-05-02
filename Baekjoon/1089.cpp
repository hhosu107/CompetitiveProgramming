#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

using ll = long long;

int main () {
  int N;
  vector<string> s(5);
  cin >> N;
  for(int i=0; i<5; i++)
    cin >> s[i];
  vector<vector<vector<int>>> loc_impossible(5, vector<vector<int>>(3, vector<int>()));
  loc_impossible[0][0] = vector<int>({1});
  loc_impossible[0][1] = vector<int>({1, 4});
  loc_impossible[1][0] = vector<int>({1, 2, 3, 7});
  loc_impossible[1][1] = vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  loc_impossible[1][2] = vector<int>({5, 6});
  loc_impossible[2][0] = vector<int>({1, 7});
  loc_impossible[2][1] = vector<int>({0, 1, 7});
  loc_impossible[3][0] = vector<int>({1, 3, 4, 5, 7, 9});
  loc_impossible[3][1] = vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  loc_impossible[3][2] = vector<int>({2});
  loc_impossible[4][0] = vector<int>({1, 4, 7});
  loc_impossible[4][1] = vector<int>({1, 4, 7});
  ll ten_base = 1;
  ll sum = 0;
  ll possible_cases_prod = 1;
  vector<ll> bydigit_sum(N, 0);
  vector<ll> possible_cases(N, 0);
  vector<ll> bases(N, 0);
  for(int i=0; i<5; i++) {
    for(int j=1; j<N; j++) {
      if (s[i][j*4-1] == '#') {
        cout << "-1\n";
        return 0;
      }
    }
  }
  for(int i=0; i<N; i++) {
    bases[i] = ten_base;
    vector<string> digit(5);
    for(int j=0; j<5; j++) {
      digit[j] = s[j].substr(4*N - 4 - 4 * i, 3);
    }
    vector<int> possible_loc(10, 1);
    for(int j=0; j<5; j++) {
      for(int k=0; k<3; k++) {
        if (digit[j][k] == '#') {
          if ((j == 1 || j == 3) && k == 1) {
            cout << "-1\n";
            return 0;
          }
          for(auto l: loc_impossible[j][k])
            possible_loc[l] = 0;
        }
      }
    }
    ll possible_case = 0;
    for(int j=0; j<10; j++)
      possible_case += possible_loc[j];
    ll possible_summation = 0;
    for(int j=0; j<10; j++) {
      possible_summation += possible_loc[j] * j;
    }
    bydigit_sum[i] = possible_summation;
    possible_cases[i] = possible_case;
    possible_cases_prod *= possible_cases[i];
    ten_base *= 10LL;
  }
  for(int i=0; i<N; i++) {
    sum += (possible_cases_prod / possible_cases[i]) * bydigit_sum[i] * bases[i];
  }
  cout << fixed << setprecision(6) << (double)(sum) / (double)(possible_cases_prod) << '\n';
  return 0;
}
