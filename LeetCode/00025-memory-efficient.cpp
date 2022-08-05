/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        // Attaching at tail leads the LinkedList to be reversed.
        ListNode* new_head = nullptr;
        ListNode* ptr = head;
        // Assume at least k nodes are in.
        
        while(k > 0) {
            // Keep track of the next node to process in the
            // original list
            ListNode* next_node = ptr->next;
            // Insert the node pointed to by "ptr"
            // at the beginning of the reversed list
            ptr->next = new_head;
            new_head = ptr;
            // Move on to the next node
            ptr = next_node;
            // Decrement the count of nodes to be reversed by 1
            k--;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = nullptr;
        
        // Head of the final, moified linked list
        ListNode* new_head = nullptr;
        
        // Keep going until there are nodes in the list
        while (ptr != nullptr) {
            
            int count = 0;
            
            // Start counting nodes from the head
            ptr = head;
            
            // Find the head of the next k nodes
            while (count < k && ptr != nullptr) {
                ptr = ptr->next;
                count += 1;
            }

            // If we counted k nodes, reverse them        
            if (count == k) {
                
                // Reverse k nodes and get the new head
                ListNode* revHead = reverseLinkedList(head, k);
                
                // new_head is the head of the final linked list
                if (new_head == nullptr)
                    new_head = revHead;
                
                // ktail is the tail of the previous block of 
                // reversed k nodes
                if (ktail != nullptr)
                    ktail->next = revHead;
                    
                ktail = head; 
                head = ptr;
            }
        }
            
         // attach the final, possibly un-reversed portion
        if (ktail != nullptr)
            ktail->next = head;
        
        return new_head == nullptr ? head : new_head;
    }
};
