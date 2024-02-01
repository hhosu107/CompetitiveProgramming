class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> removed_result;
    int source_lines = source.size();
    string curr_valid_string = "";
    int valid_row_before_comment = 0;
    bool encountered_block_comment = false;
    for (int i = 0; i < source_lines; i++) {
      if (!encountered_block_comment)
        curr_valid_string = "";
      int j = 0;
      while (j < source[i].length()) {
        if (source[i][j] == '*') {
          if (encountered_block_comment && j + 1 < source[i].length() &&
              source[i][j + 1] == '/') {
            encountered_block_comment = false;
            j += 2;
          } else if (encountered_block_comment)
            j += 1;
          else {
            curr_valid_string += source[i][j];
            j += 1;
          }
        } else if (source[i][j] == '/') {
          if (!encountered_block_comment && j + 1 < source[i].length() &&
              source[i][j + 1] == '/') {
            break;
          } else if (!encountered_block_comment && j + 1 < source[i].length() &&
                     source[i][j + 1] == '*') {
            encountered_block_comment = true;
            valid_row_before_comment = i;
            j += 2;
          } else if (encountered_block_comment) {
            j += 1;
          } else {
            curr_valid_string += source[i][j];
            j += 1;
          }
        } else if (!encountered_block_comment) {
          curr_valid_string += source[i][j];
          j += 1;
        } else
          j += 1;
      }
      if (!encountered_block_comment && curr_valid_string != "") {
        removed_result.push_back(curr_valid_string);
        curr_valid_string = "";
      }
    }
    return removed_result;
  }
};
