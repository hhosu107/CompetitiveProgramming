class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* frontNode = nullptr;
        ListNode* endNode = nullptr;
        ListNode* currentNode = head;
        // set the front node and end node in single pass
        while (currentNode) {
            listLength++;
             if(endNode != NULL) {
                endNode = endNode->next;
             }
            // check if we have reached kth node
            if (listLength == k) {
                frontNode = currentNode;
                endNode = head;
            }          
            currentNode = currentNode->next;
        }
        // swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
};
// One-pass solution: using two pointer.
// 1) find the kth front pointer. Then, apply head to the new pointer.
// 2) until the dummy head reaches nullptr, find next of the new pointer.
// 3) That new pointer becomes the n-k+1th front pointer (since: when we found
// kth front pointer, that pointer was pointing 1st front pointer).
