/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

/* Idea:
 * 1) If they are on the different level, assign parent to the deeper one until
 * they have the same level.
 * 2) Until they become the same, assign parents for both.
 */
class Solution {
public:
    int depth(Node* p) {
        if (p->parent == nullptr) return 0;
        return 1 + depth(p->parent);
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int dp = depth(p);
        int dq = depth(q);
        while(dp != dq) {
            if (dp > dq) {
                p = p->parent;
                dp--;
            } else {
                q = q->parent;
                dq--;
            }
        }
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};
