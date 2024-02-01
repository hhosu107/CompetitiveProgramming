class Solution {
public:
  vector<string> letterCombinations(string digits) {
    // Sol) Use queue.
    if (digits == "")
      return vector<string>();
    queue<string> letterCombinationQueue;
    letterCombinationQueue.push("");
    map<char, vector<char>> digit_chars;
    digit_chars['2'] = vector<char>{'a', 'b', 'c'};
    digit_chars['3'] = vector<char>{'d', 'e', 'f'};
    digit_chars['4'] = vector<char>{'g', 'h', 'i'};
    digit_chars['5'] = vector<char>{'j', 'k', 'l'};
    digit_chars['6'] = vector<char>{'m', 'n', 'o'};
    digit_chars['7'] = vector<char>{'p', 'q', 'r', 's'};
    digit_chars['8'] = vector<char>{'t', 'u', 'v'};
    digit_chars['9'] = vector<char>{'w', 'x', 'y', 'z'};
    for (int i = 0; i < digits.length(); i++) {
      string fr = letterCombinationQueue.front();
      char digit = digits[i];
      while (fr.length() == i) {
        letterCombinationQueue.pop();
        for (char n : digit_chars[digit]) {
          letterCombinationQueue.push(fr + n);
        }
        fr = letterCombinationQueue.front();
      }
    }
    vector<string> res;
    while (!letterCombinationQueue.empty()) {
      string x = letterCombinationQueue.front();
      letterCombinationQueue.pop();
      res.emplace_back(x);
    }
    return res;
  }
};
