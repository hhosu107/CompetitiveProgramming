#include <iostream>
#include <vector>

using namespace std;

/* Learn how to construct singly linked list.
 * 1. Tail extension
  ListNode *r1 = new ListNode(9);
  ListNode *r2 = r1;
  for(int i=0; i<4; i++){
    ListNode *r3 = new ListNode(i);
    r2->next = r3;
    r2 = r3; // r2 moves to r3 which is the next element. I.e., Tail goes
 further.
  }
  * 2. Head extension
  for(int i=0; i<4; i++){
    ListNode *r3 = new ListNode(i);
    r3->next = r1;
    r1 = r3; // r1 moves to r3 which points r1. I.E., Head goes further.
  }
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode(0);
  ListNode *tail = head;
  ListNode *sumTailFront = nullptr;
  while (l1 != nullptr || l2 != nullptr) {
    int sumval = 0;
    if (l1 != nullptr) {
      sumval += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      sumval += l2->val;
      l2 = l2->next;
    }
    sumval += tail->val;
    int over = sumval / 10;
    sumval = (sumval % 10);
    ListNode *overnode = new ListNode(over);
    tail->val = sumval;
    tail->next = overnode;
    sumTailFront = tail;
    tail = overnode;
  }
  if (tail->val == 0) {
    tail = sumTailFront;
    sumTailFront->next = nullptr;
  }
  return head;
}

int main() {
  ListNode *r1 = new ListNode(9);
  ListNode *r2 = r1;
  /* for(int i=0; i<4; i++){
    ListNode *r3 = new ListNode(i);
    r2->next = r3;
    r2 = r3;
  }
  */
  for (int i = 0; i < 4; i++) {
    ListNode *r3 = new ListNode(i);
    r3->next = r1;
    r1 = r3;
  }
  ListNode *r4 = new ListNode(9);
  ListNode *r5 = r4;
  for (int i = 8; i >= 6; i--) {
    ListNode *r6 = new ListNode(i);
    r6->next = r4;
    r4 = r6;
  }
  ListNode *sum = addTwoNumbers(r1, r4);
  while (sum != nullptr) {
    cout << sum->val << " ";
    sum = sum->next;
  }
  cout << endl;
  return 0;
}
