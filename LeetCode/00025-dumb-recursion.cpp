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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummyNode = new ListNode(-1, head);
    ListNode *origin_tracker = head;
    ListNode *k_tracker = dummyNode;
    ListNode *mut_head = new ListNode(-1, nullptr);
    ListNode *mut_tracker = mut_head;
    stack<ListNode *> altering_nodes;
    int node_cnt = 0;
    while (origin_tracker != nullptr) {

      altering_nodes.push(origin_tracker);
      node_cnt += 1;
      if (node_cnt == k) {
        while (!altering_nodes.empty()) {
          ListNode *curr = new ListNode(altering_nodes.top()->val);
          altering_nodes.pop();
          mut_tracker->next = curr;
          mut_tracker = mut_tracker->next;
        }
        node_cnt = 0;
      }
      if (node_cnt == 0) {
        k_tracker = origin_tracker;
      }
      origin_tracker = origin_tracker->next;
    }
    if (node_cnt != 0) {
      while (k_tracker->next != nullptr) {
        mut_tracker->next = k_tracker->next;
        k_tracker = k_tracker->next;
        mut_tracker = mut_tracker->next;
      }
    }
    return mut_head->next;
  }
};
