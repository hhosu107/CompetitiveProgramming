# longest palindromic substring
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        i, l = 0, 0
        # flip every possible string that ends at j with 1 or 2 characters longer one.
        for j in range(len(s)):
            if s[j - l : j + 1] == s[j - l : j + 1][::-1]:
                i, l = j - l, l + 1
            elif j - l > 0 and s[j - l - 1 : j + 1] == s[j - l - 1 : j + 1][::-1]:
                i, l = j - l - 1, l + 2
        return s[i : i + l]
