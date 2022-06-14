/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        // constant space complexity method
        int list_len = 0;
        ImmutableListNode *follow = head;
        do {
            list_len += 1;
            follow = follow->getNext();
        } while (follow != nullptr);
        for(int i=list_len - 1; i >= 0; i--) {
            ImmutableListNode *rev_const = head;
            for(int j=0; j<i; j++) {
                rev_const = rev_const->getNext();
            }
            rev_const->printValue();
        }
    }
};

// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/discuss/445408/Py-5-time-space-combinations-space-O(n)-O(n)-O(lg-n)-O(1)#sqrt-decomposition
//
class Solution {
public:
    void printLinkedListInReverseDirectly(ImmutableListNode* head, int size) {
        if (head != nullptr && size > 0) {
            printLinkedListInReverseDirectly(head->getNext(), size - 1);
            head->printValue();
        }
    }
    
    void printLinkedListInReverse(ImmutableListNode* head) {
        // constant space complexity method
        int list_len = 0;
        ImmutableListNode *follow = head;
        do {
            list_len += 1;
            follow = follow->getNext();
        } while (follow != nullptr);
        // sqrt sized space: sqrt size of array, sqrt count of call stack
        int block_size = ceil(sqrt(list_len));
        stack<ImmutableListNode*> rev_divided_nodes;
        ImmutableListNode *temp = head;
        for(int i=0; i<list_len; i++) {
            if (i % block_size == 0) {
                ImmutableListNode *ttemp = temp;
                rev_divided_nodes.push(ttemp);
            }
            temp = temp->getNext();
        }
        while(!rev_divided_nodes.empty()) {
            ImmutableListNode *temp = rev_divided_nodes.top();
            rev_divided_nodes.pop();
            printLinkedListInReverseDirectly(temp, block_size);
        }
    }
};
