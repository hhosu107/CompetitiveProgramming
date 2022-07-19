/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        if (s.length() == 1) return new Node(s[0]);
        // Stack to hold nodes (valid sub-expressions)
        stack<Node*> stN;
 
        // Stack to hold operators
        stack<char> stC;
        Node* t, t1, t2;
 
        // Prioritising the operators
        unordered_map<char, int> p;
        p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p[')'] = 0;
 
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') {
 
                // Push '(' in char stack
                stC.push(s[i]);
            }
 
            // Push the operands in node stack
            else if (isdigit(s[i]))
            {
                t = new Node(s[i]);
                stN.push(t);
            }
            else if (p[s[i]] > 0)
            {
                // If an operator with lower or
                // same associativity appears
                while (!stC.empty() && stC.top() != '(' && p[stC.top()] >= p[s[i]])
                {
 
                    // Get and remove the top element
                    // from the character stack
                    t = new Node(stC.top());
                    stC.pop();
 
                    // Get and remove the top element
                    // from the node stack
                    // Since last inserted element is located rightmost,
                    // put this element to the right.
                    t->right = stN.top();
                    stN.pop();
 
                    // Get and remove the currently top
                    // element from the node stack
                    // Vice versa. put this element to the left.
                    t->left = stN.top();
                    stN.pop();
 
                    // Push the node to the node stack
                    stN.push(t);
                }
 
                // Push s[i] to char stack
                stC.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!stC.empty() && stC.top() != '(')
                {
                    t = new Node(stC.top());
                    stC.pop();
                    t->right = stN.top();
                    stN.pop();
                    t->left = stN.top();
                    stN.pop();
                    stN.push(t);
                }
                stC.pop();
            }
        }
        while (!stC.empty()) {
            t = new Node(stC.top());
            stC.pop();
            t->right = stN.top();
            stN.pop();
            t->left = stN.top();
            stN.pop();
            stN.push(t);
        }
        t = stN.top();
        return t;
    }
};
