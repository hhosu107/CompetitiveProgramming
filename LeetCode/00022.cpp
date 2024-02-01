#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 20;

vector<string> print_parens(int pos, int n, int open, int close) {
  static char str[MAX_SIZE];
  vector<string> res = vector<string>();
  if (close == n) {
    string res(str);
    return vector<string>(1, res);
  }
  if (open > close) { // can attach close parenthesis
    str[pos] = ')';
    vector<string> closings = print_parens(pos + 1, n, open, close + 1);
    res.reserve(res.size() + distance(closings.begin(), closings.end()));
    res.insert(res.end(), closings.begin(), closings.end());
  }
  if (open < n) { // can attach open parenthesis
    str[pos] = '(';
    vector<string> openings = print_parens(pos + 1, n, open + 1, close);
    res.reserve(res.size() + distance(openings.begin(), openings.end()));
    res.insert(res.end(), openings.begin(), openings.end());
  }
  return res;
}

int main() {
  for (int i = 1; i <= 4; i++) {
    vector<string> parens = print_parens(0, i, 0, 0);
    for (string paren : parens)
      cout << paren << ' ';
    cout << endl;
  }
  return 0;
}
