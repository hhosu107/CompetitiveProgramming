class Solution {
public:
    int maxPower(string s) {
        char curr_power = s[0];
        int max_power = 1;
        int curr_power_val = 1;
        for(int i=1; i<s.length(); i++) {
            if (curr_power != s[i]) {
                max_power = max(max_power, curr_power_val);
                curr_power = s[i];
                curr_power_val = 1;
            } else curr_power_val += 1;
        }
        return max(max_power, curr_power_val);
    }
};
