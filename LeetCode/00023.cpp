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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num_lists = lists.size();
        auto min_comp = [](const pii &a, const pii &b){return a.first > b.first || (a.first == b.first && a.second > b.second);};
        priority_queue<pii, vector<pii>, decltype(min_comp)> pq(min_comp);
        for(int i=0; i<num_lists; i++){
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, i});
            }
        }
        stack<int> sorted_val;
        while(!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            sorted_val.push(curr.first);
            lists[curr.second] = lists[curr.second]->next;
            if (lists[curr.second] != nullptr) {
                pq.push({lists[curr.second]->val, curr.second});
            }
        }
        ListNode* head = nullptr;
        while(!sorted_val.empty()) {
            int top_val = sorted_val.top();
            sorted_val.pop();
            ListNode* new_head = new ListNode(top_val, head);
            head = new_head;
        }
        return head;
    }
};
