class Solution {
public:
  using pii = pair<int, int>;
  pii char_idx(char x) {
    int char_idx = (int)(x - 'a');
    return make_pair(char_idx / 5, char_idx % 5);
  }
  string alphabetBoardPath(string target) {
    string result = "";
    pii init_idx = make_pair(0, 0);
    for (char x : target) {
      pii x_idx = char_idx(x);
      int vertical_diff = x_idx.first - init_idx.first;
      int horizontal_diff = x_idx.second - init_idx.second;
      if (horizontal_diff > 0) {
        if (vertical_diff > 0) {
          for (int i = 0; i < vertical_diff; i++) {
            result += "D";
          }
        } else {
          for (int i = 0; i < abs(vertical_diff); i++) {
            result += "U";
          }
        }
        for (int i = 0; i < horizontal_diff; i++) {
          result += "R";
        }
      } else {
        for (int i = 0; i < abs(horizontal_diff); i++) {
          result += "L";
        }
        if (vertical_diff > 0) {
          for (int i = 0; i < vertical_diff; i++) {
            result += "D";
          }
        } else {
          for (int i = 0; i < abs(vertical_diff); i++) {
            result += "U";
          }
        }
      }
      result += "!";
      init_idx = x_idx;
    }
    return result;
  }
};
