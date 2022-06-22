/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        long long int valueSum = 0;
        for(Node *node: tree) {
            valueSum += node->val;
            for (Node *n: node->children)
                valueSum -= n->val;
        }
        for (Node *node : tree) {
            if (node->val == valueSum) {
                return node;
            }
        }
        return nullptr;
    }
};
// Idea: We have an array of all nodes, where childs are all nodes except one.
// Thus, we watch all childs value twice, whereas the root's value once.
// Sum up all values to the sum, and subtract all child's values to the sum.
// The remaining one is the value of the root.
// Since all values are unique, after we calculate the root's value, we can find
// it in O(n) additional time.
