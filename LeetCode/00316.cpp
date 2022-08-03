/*
 * First we should make sure we understand what "lexicographical order" means. Comparing strings doesn't work the same way as comparing numbers. Strings are compared from the first character to the last one. Which string is greater depends on the comparison between the first unequal corresponding character in the two strings. As a result any string beginning with a will always be less than any string beginning with b, regardless of the ends of both strings.

Because of this, the optimal solution will have the smallest characters as early as possible. We draw two conclusions that provide different methods of solving this problem in O(N):

The leftmost letter in our solution will be the smallest letter such that the suffix from that letter contains every other. This is because we know that the solution must have one copy of every letter, and we know that the solution will have the lexicographically smallest leftmost character possible.

If there are multiple smallest letters, then we pick the leftmost one simply because it gives us more options. We can always eliminate more letters later on, so the optimal solution will always remain in our search space.

As we iterate over our string, if character i is greater than character i+1 and another occurrence of character i exists later in the string, deleting character i will always lead to the optimal solution. Characters that come later in the string i don't matter in this calculation because i is in a more significant spot. Even if character i+1 isn't the best yet, we can always replace it for a smaller character down the line if possible.

Since we try to remove characters as early as possible, and picking the best letter at each step leads to the best solution, "greedy" should be going off like an alarm.

We use idea number two from the intuition. We will keep a stack to store the solution we have built as we iterate over the string, and we will delete characters off the stack whenever it is possible and it makes our string smaller.

Each iteration we add the current character to the solution if it hasn't already been used. We try to remove as many characters as possible off the top of the stack, and then add the current character

The conditions for deletion are:

The character is greater than the current characters
The character can be removed because it occurs later on
At each stage in our iteration through the string, we greedily keep what's on the stack as small as possible.

The following animation makes this more clear:

Time complexity : O(N)O(N). Although there is a loop inside a loop, the time complexity is still O(N)O(N). This is because the inner while loop is bounded by the total number of elements added to the stack (each time it fires an element goes). This means that the total amount of time spent in the inner loop is bounded by O(N)O(N), giving us a total time complexity of O(N)O(N)

Space complexity : O(1)O(1). At first glance it looks like this is O(N)O(N), but that is not true! seen will only contain unique elements, so it's bounded by the number of characters in the alphabet (a constant). You can only add to stack if an element has not been seen, so stack also only consists of unique elements. This means that both stack and seen are bounded by constant, giving us O(1)O(1) space complexity.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> chars; // this one always contains unique character.
        unordered_set<char> seen_chars; // this one indicates what characters are in the stack.
        unordered_map<char, int> last_occ; // The character we want to eliminate (to make the entire string smaller) from the stack cannot be eliminated since current index is bigger than stack to character's last occurrence.
        for(int i=0; i<s.length(); i++)
            last_occ[s[i]] = i;
        for(int i=0; i<s.length(); i++) {
            if (seen_chars.find(s[i]) == seen_chars.end()) {
                while(!chars.empty() && s[i] < chars.top() && i < last_occ[chars.top()]) {
                    seen_chars.erase(chars.top());
                    chars.pop();
                }
                seen_chars.insert(s[i]);
                chars.push(s[i]);
            }
        }
        string reversed_occ = "";
        while(!chars.empty()) {
            reversed_occ += chars.top();
            chars.pop();
        }
        reverse(reversed_occ.begin(), reversed_occ.end());
        return reversed_occ;
    }
};
