class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> rev_unique;
    for (char x : s) {
      if (rev_unique.empty() || rev_unique.top() != x)
        rev_unique.push(x);
      else
        rev_unique.pop();
    }
    string rev = "";
    while (!rev_unique.empty()) {
      rev += rev_unique.top();
      rev_unique.pop();
    }
    reverse(rev.begin(), rev.end());
    return rev;
  }
};
