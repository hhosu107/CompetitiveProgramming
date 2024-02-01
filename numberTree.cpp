#include <cstdio>
#include <iostream>
using namespace std;
int N;

int parse_tree(int suff, int (&input_str)[100001]) {
  if (input_str[suff] == -1)
    return suff + 1;
  if (suff + 1 >= N)
    return -1;
  int l = parse_tree(suff + 1, input_str);
  if (l > N)
    return -1;
  int r;
  if (l < N) {
    r = parse_tree(l, input_str);
  } else
    r = N;
  if (r > N)
    return -1;
  return r;
}

int main() {
  int input[100001];
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> input[i];
  int result = parse_tree(0, input);
  cout << (result > 0 ? 1 : 0) << '\n';
  return 0;
}
