/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        // From the linked list A->B->C->..., make a linked list A->A'->B->B'->C->C'->... (original's address value remains the same)
        Node* ptr = head;
        while(ptr != nullptr) {
            Node* new_node = new Node(ptr->val);
            // Insert new node with the same value as ptr.
            //  new_node->next = ptr->next; ptr->next = new_node;
            new_node->next = ptr->next;
            ptr->next = new_node;
            ptr = new_node->next;
        }
        
        ptr = head;
        
        // Link random pointers.
        // if original node's random pointer is ptr->random, by construction, the copy pointer's random must be ptr->random->next!
        while(ptr != nullptr) {
            ptr->next->random = (ptr->random != nullptr) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        
        // Break into two to recover original list and construct the new list.
        Node *ptr_old_list = head; // A->B->C->...
        Node *ptr_new_list = head->next; // A'->B'->C'->...
        Node *head_old = head->next;
        while(ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next; // recover A->B from A->A'->B
            ptr_new_list->next = (ptr_new_list->next != nullptr) ? ptr_new_list->next->next : nullptr; // recover A'->B' from A'->B->B'
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_old;
    }
};
