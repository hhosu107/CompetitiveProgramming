#include<string>
#include<algorithm>
#include<vector>

class Solution {
private:
    int numchars[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
    vector<string> postfixLetters(string digits, int len, int idx){
        if (idx == len) return vector<string>(1, "");
        else {
            vector<string> nextPostfixes = postfixLetters(digits, len, idx + 1);
            vector<string> postfixes = vector<string>();
            int currChar = (int)(digits[idx] - '0');
            for(int i=numchars[currChar - 2]; i<numchars[currChar - 1]; i++){
                string curr (1, (char)((int)('a' + i)));
                for(string next : nextPostfixes) {
                    postfixes.push_back(curr + next);
                }
            }
            return postfixes;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if (len == 0) return vector<string>();
        return postfixLetters(digits, len, 0);
    }
};
