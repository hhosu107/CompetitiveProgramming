// Multiply strings leetcode.com/problems/multiply-strings
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.compare("0") == 0 || num2.compare("0") == 0) return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int curr = 0;
        string rres = "";
        int len1 = num1.length();
        int len2 = num2.length();
        for(int i=0; i<len1 + len2 - 1; i++){
            curr = carry;
            carry = 0;
            int currdigit = 0;
            for(int j=0; j<=i; j++){
                if (j >= len1 || i-j >= len2) continue;
                currdigit += (int)(num1[j] - '0') * (int)(num2[i-j] - '0');
            }
            currdigit += curr;
            carry = (currdigit) / 10;
            currdigit %= 10;
            rres += (char)(currdigit + '0');
        }
        while(carry > 0){
            rres += (char)((carry % 10) + '0');
            carry /= 10;
        }
        reverse(rres.begin(), rres.end());
        return rres;
    }
};
