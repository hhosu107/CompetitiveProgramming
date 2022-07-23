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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* it = new ListNode(0, head);
        int leave_cnt = 0;
        int remove_cnt = 0;
        while(it != nullptr) {
            if (leave_cnt == m && remove_cnt == n) {
                leave_cnt = 0;
                remove_cnt = 0;
                continue;
            }
            if (leave_cnt < m) {
                it = it->next;
                leave_cnt++;
            } else if (remove_cnt < n) {
                if (it->next != nullptr) {
                    it->next = it->next->next;
                } else {
                    break;
                }
                remove_cnt++;
            }
        }
        return head;
    }
};
