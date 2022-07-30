class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> st;
        st.push(-1); // virtual ')'
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop(); // since ')' is the possible endpoint.
                if (st.empty()) {
                    st.push(i); // This is the invalid endpoint.
                } else {
                    maxans = max(maxans, i - st.top());
                }
            }
        }
        return maxans;
    }
};
