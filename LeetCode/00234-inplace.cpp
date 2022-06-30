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
    /* 1. Find the end of the first half.
    2. Reverse the second half.
    3. Determine whether or not there is a palindrome (since 2's length is the same or 1 less than 1, tracking each pointer returns the result.)
    4. Restore the list (since we reversed that in-place)
    5. Return the result
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
            // By doing this, current is curr->next, curr->next is curr.
        }
        return prev;
    }
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; // By doing this, slow might be the center (in case of length odd), or the left center (in case of length even)
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next); // reversed head of second half
        
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) { // p2 is shorter or equal to p1.
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // Restore the list.
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
        
    }
};
