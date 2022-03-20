#include<bits/stdc++.h>

using namespace std;

/* I think the idea that constructs local 15~16 length-ed substring is right,
 * but it needs to be fixed. */

/* Large: We are only interested in the maximum length 10 substring.
 * Why?
 * Think about the case 100??100.
 * If we fill ?? as 00, 10, or 11, we can avoid length>=5 palindroms for the
 * first length 5 substring.
 * But, after we move on, 00 makes 00100 as a palindrome, 10 makes 01010 as a
 * palindrome, 11 make 01110 as a palindrome.
 * Then how can we construct non-palindrome when there are too many ?s?
 */
/* len 5 non palindrome:
 * 00001  * 00010  * 00011  * 00101  * 00110  * 00111
 * 01000  * 01001  * 01011  * 01100  * 01101  * 01111
 * 10000  * 10010  * 10011  * 10100  * 10110  * 10111
 * 11000  * 11001  * 11010  * 11100  * 11101  * 11110
 */
/* len 6 non palindrome that doesn't contain len4 non palindrome?:
 * 000010  * 000011  * 000101  * 000110  * 000111  * 001011
 * 001101  * 001111  * 010000  * 010011  * 010110
 * 010111  * 011000  * 011001  * 011010  * 011111
 * 100101  * 100110  * 100111  * 101000
 * 101001  * 101100  * 101111  * 110000
 * 110010  * 110100  * 111001  * 111010  * 111100 * 111101
 */
/* Idea: For the last unrecognized ?, select -5 ~ 5 substring.
 * (Condition: Characters that are located 6 or more left side of the select ?
 * are already fixed.)
 * If there is a pattern that makes that substring doesn't contain 5~6
 * palindromes,
 * we can replace ?s within that substring: up to selected ?.
 * And then move the cursor to the next ?.
 */

using pbs = pair<bool, string>;

pbs q_fill_no_palindrome(string s, vector<int> &q, vector<int> filler, int n) {
  if (q.size() == n) {
    string x = s;
    for(int i=0; i<n; i++) {
      x[q[i]] = (char)(filler[i] + '0');
    }
    int max_len = s.size() * 2 - 1;
    for(int st = 4; st < max_len - 4; st++) {
      bool non_palindrome = false;
      for(int delta = 0; delta <= 4; delta += 2) {
        int real_delta = (st % 2 == 0 ? delta : delta + 1);
        if (x[(st - real_delta) / 2] != x[(st + real_delta) / 2]) {
          non_palindrome = true;
          break;
        }
      }
      if (!non_palindrome) {
        return {false, x};
      }
    }
    return {true, x};
  }
  else {
    pbs flag = q_fill_no_palindrome(s, q, filler, n + 1);
    if (flag.first) return flag;
    filler[n] = 1;
    flag = q_fill_no_palindrome(s, q, filler, n + 1);
    return flag;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T, n;
  string q;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    cin >> q;
    vector<int> q_or_not(n);
    for(int i=0; i<n; i++) {
      q_or_not[i] = (q[i] == '?' ? 1 : 0);
    }
    int checked_pos = 0;
    bool master_flag = true;
    while(checked_pos < n) {
      if (q_or_not[checked_pos] == 0) {
        checked_pos++;
        continue;
      } else {
        vector<bool> possible_replacement(2, true);
        int max_left = min(checked_pos, 5);
        int max_right = min(n - checked_pos, 11);
        string testq = q;
        pbs leftflag, rightflag;
        if (possible_replacement[0]) {
          testq[checked_pos] = '0';
          vector<int> q_loc = vector<int>();
          for(int i=-max_left; i<max_right; i++) {
            if (q_or_not[checked_pos + i] == 1) {
              q_loc.push_back(i + max_left);
            }
          }
          vector<int> filler(q_loc.size(), 0);
          string sub_q = testq.substr(checked_pos - max_left, max_left + max_right);
          leftflag = q_fill_no_palindrome(sub_q, q_loc, filler, 0);
          possible_replacement[0] = leftflag.first;
        }
        if (possible_replacement[1]) {
          testq[checked_pos] = '1';
          vector<int> q_loc = vector<int>();
          for(int i=-max_left; i<max_right; i++) {
            if (q_or_not[checked_pos + i] == 1) {
              q_loc.push_back(i + max_left);
            }
          }
          vector<int> filler(q_loc.size(), 0);
          string sub_q = testq.substr(checked_pos - max_left, max_left + max_right);
          rightflag = q_fill_no_palindrome(sub_q, q_loc, filler, 0);
          possible_replacement[1] = rightflag.first;
        }
        if (!possible_replacement[0] && !possible_replacement[1]) {
          master_flag = false;
          break;
        }
        else if (n - checked_pos <= 11) {
          break;
        } else {
          int ensure_index = max(max_right - 6, 0);
          if(possible_replacement[0]) {
            for(int i=0; i<=max_left + ensure_index; i++) {
              q[checked_pos - max_left + i] = leftflag.second[i];
            }
          } else {
            for(int i=0; i<=max_left + ensure_index; i++) {
              q[checked_pos - max_left + i] = rightflag.second[i];
            }
          }
          checked_pos += ensure_index + 1;
        }
      }
    }
    cout << "Case #" << t << ": " << (master_flag ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }
  return 0;
}
