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
    using pnn = pair<ListNode*, ListNode*>;
    pnn revPosNode(ListNode* prev, ListNode* head, int k, int curr, int &size) {
        if (head == nullptr) {
            ListNode* dummyTail = new ListNode(0, nullptr);
            prev->next = dummyTail;
            return make_pair(prev, dummyTail);
        }
        size += 1;
        pnn revNode = revPosNode(head, head->next, k, curr + 1, size);
        if (size - curr > k) return revNode;
        else if (size - curr == k) return make_pair(prev, head);
        else return make_pair(prev, nullptr);
    }
    pnn PosNode(ListNode* prev, ListNode* head, int k, int curr) {
        if (head == nullptr) return make_pair(prev, nullptr);
        if (curr + 1 == k) return make_pair(prev, head);
        return PosNode(head, head->next, k, curr + 1);
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        auto [rightPrev, rightHead] = PosNode(dummyHead, head, k, 0);
        int listSize = 0;
        auto [leftPrev, leftHead] = revPosNode(dummyHead, head, k, 0, listSize);
        auto [prevRealTail, realTail] = PosNode(dummyHead, head, listSize, 0);
        if (rightHead == leftHead) {
            realTail->next = nullptr;
            return head;
        }
        // (currently rightPrev -> rightHead -> rightHead->next / leftPrev -> leftHead -> leftHead->next.)
        // (todo : rightPrev -> leftHead -> rightHead->next / leftPrev -> rightHead -> leftHead->next.)
        // 1. Normal case.
        ListNode* returnHead = (k == 1 || k == listSize ? leftHead : head);
        if (k == 1 || k == listSize) {
            if (listSize == 2) {
                head->next = nullptr;
                realTail->next = head;
                return realTail;
            }
            // swap head and realTail.
            realTail->next = head->next;
            prevRealTail->next = head;
            head->next = nullptr;
            return realTail;
        }
        if (leftPrev == rightHead) {
            rightHead->next = leftHead->next;
            leftHead->next = rightHead;
            rightPrev->next = leftHead;
        } else if (rightPrev == leftHead) {
            leftHead->next = rightHead->next;
            rightHead->next = leftHead;
            leftPrev->next = rightHead;
        } else {
            ListNode* dummyRightNext = rightHead->next;
            rightHead->next = leftHead->next;
            leftHead->next = dummyRightNext;
            rightPrev->next = leftHead;
            leftPrev->next = rightHead;
        }
        realTail->next = nullptr;
        return returnHead;
    }
};
// Sol) I tried to swap two nodes (three pass: find kth node, find n-k+1th node,
// find nth node). But the description just asked me to swap the ""VALUES"", so
// these long range edge-case dividing work was not required; only
// swap(leftHead->val, rightHead->val) was required.
