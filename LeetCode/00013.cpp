class Solution {
public:
    unordered_map<string, int> roman_arabic;
    int romanToInt(string s) {
        int len = s.length();
        roman_arabic["I"] = 1;
        roman_arabic["II"] = 2;
        roman_arabic["III"] = 3;
        roman_arabic["IV"] = 4;
        roman_arabic["V"] = 5;
        roman_arabic["VI"] = 6;
        roman_arabic["VII"] = 7;
        roman_arabic["VIII"] = 8;
        roman_arabic["IX"] = 9;
        roman_arabic["X"] = 10;
        roman_arabic["XX"] = 20;
        roman_arabic["XXX"] = 30;
        roman_arabic["XL"] = 40;
        roman_arabic["L"] = 50;
        roman_arabic["LX"] = 60;
        roman_arabic["LXX"] = 70;
        roman_arabic["LXXX"] = 80;
        roman_arabic["XC"] = 90;
        roman_arabic["C"] = 100;
        roman_arabic["CC"] = 200;
        roman_arabic["CCC"] = 300;
        roman_arabic["CD"] = 400;
        roman_arabic["D"] = 500;
        roman_arabic["DC"] = 600;
        roman_arabic["DCC"] = 700;
        roman_arabic["DCCC"] = 800;
        roman_arabic["CM"] = 900;
        roman_arabic["M"] = 1000;
        roman_arabic["MM"] = 2000;
        roman_arabic["MMM"] = 3000;
        vector<string> finding_order{"MMM", "MM", "M", "CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", "XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X", "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"};
        int patterns_len = finding_order.size();
        int parsed_chars = 0;
        int s_len = s.length();
        int parsed_int = 0;
        int seek_patterns = 0;
        while(parsed_chars < s_len && seek_patterns < patterns_len) {
            if (finding_order[seek_patterns].length() + parsed_chars <= s_len && s.substr(parsed_chars, finding_order[seek_patterns].length()) == finding_order[seek_patterns]) {
                parsed_chars += finding_order[seek_patterns].length();
                parsed_int += roman_arabic[finding_order[seek_patterns]];
            }
            seek_patterns += 1;
        }
        return parsed_int;
    }
};
