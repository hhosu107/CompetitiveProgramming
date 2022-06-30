/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node* pseudoHead = new Node(0, nullptr, head, nullptr); // To ensure the 'prev' pointer is never none.
        flattenDFS(pseudoHead, head); // No return value needed since we already have pseudoHead.
        pseudoHead->next->prev = nullptr; // detach pseudo head from the real head to make real head not pointting pseudoHead.
        return pseudoHead->next;
    }
    
    Node* flattenDFS(Node *prev, Node *curr) { // prev node doesn't have the connection between the current node, so connect both.
        if (curr == nullptr) return prev;
        curr->prev = prev;
        prev->next = curr;
        
    // curr->next would be tempered (changed) in the recursive function; so save that.
        Node* tempNext = curr->next;
        Node* tail = flattenDFS(curr, curr->child);
        curr->child = nullptr; // Remove all-seen child.
        return flattenDFS(tail, tempNext);
    }
};
