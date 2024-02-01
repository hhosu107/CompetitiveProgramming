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
using pii = pair<int, int>;
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int num_lists = lists.size();
    auto min_comp = [](const pii &a, const pii &b) {
      return a.first > b.first || (a.first == b.first && a.second > b.second);
    };
    priority_queue<pii, vector<pii>, decltype(min_comp)> pq(min_comp);
    for (int i = 0; i < num_lists; i++) {
      if (lists[i] != nullptr) {
        pq.push({lists[i]->val, i});
      }
    }
    ListNode *head_dummy = new ListNode(-100000);
    ListNode *tail = head_dummy;
    while (!pq.empty()) {
      pii curr = pq.top();
      pq.pop();
      tail->next = new ListNode(curr.first);
      tail = tail->next;
      lists[curr.second] = lists[curr.second]->next;
      if (lists[curr.second] != nullptr)
        pq.push({lists[curr.second]->val, curr.second});
    }
    return head_dummy->next;
  }
};
