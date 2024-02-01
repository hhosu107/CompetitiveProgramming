#include <ctime>
#include <functional>
#include <iostream>
#include <random>

class QuadNode {
public:
  int val;
  QuadNode *prev;
  QuadNode *next;
  QuadNode *ancestor;
  QuadNode *child;
  QuadNode(int val)
      : val(val), prev(nullptr), next(nullptr), ancestor(nullptr),
        child(nullptr) {}
  QuadNode *search(int target) {
    if (this->val == target)
      return this;
    else if (this->next->val <= target)
      return this->next->search(target);
    else if (this->child == nullptr)
      return this;
    else
      return this->child->search(target);
  }
  ~QuadNode();
};

class QuadNodeList {
public:
  QuadNode *head;
  QuadNode *tail;
  QuadNodeList() {
    head = new QuadNode(-1000000);
    tail = new QuadNode(1000000);
    head->next = tail;
    tail->prev = head;
  }
  bool search(int target) {
    QuadNode *curr = head;
    QuadNode *found = curr->search(target);
    return found != nullptr && found->val == target;
  }
  QuadNode *insert(int target) {
    QuadNode *curr = head;
    while (curr->next->val < target)
      curr = curr->next;
    // head->next's val is greater than or equal to the target.
    QuadNode *new_node = new QuadNode(target);
    new_node->next = curr->next;
    new_node->prev = curr;
    curr->next->prev = new_node;
    curr->next = new_node;
    return new_node;
  }
  QuadNode *insert(int target, QuadNode *inserted) {
    QuadNode *curr = insert(target);
    curr->ancestor = inserted;
    inserted->child = curr;
    return curr;
  }
  bool erase(int target) {
    QuadNode *curr = head;
    QuadNode *found = curr->search(target);
    if (found != nullptr && found->val == target) {
      while (found->ancestor != nullptr)
        found = found->ancestor;
      while (found != nullptr) {
        found->next->prev = found->prev;
        found->prev->next = found->next;
        QuadNode *found_child = found->child;
        found = found_child;
        // found_child->ancestor = nullptr;
        // found->child = nullptr;
        // found = found->child;
      }
      return true;
    } else
      return false;
  }
};

class Skiplist {
public:
  int maxLevel;
  vector<QuadNodeList> leveled_lists;
  Skiplist() {
    maxLevel = 20;
    leveled_lists = vector<QuadNodeList>(20);
    for (int i = 0; i < maxLevel; i++)
      leveled_lists[i] = QuadNodeList();
    for (int i = 0; i < 20; i++) {
      if (i > 0) {
        leveled_lists[i].head->child = leveled_lists[i - 1].head;
        leveled_lists[i].tail->child = leveled_lists[i - 1].tail;
      }
      if (i < 19) {
        leveled_lists[i].head->ancestor = leveled_lists[i + 1].head;
        leveled_lists[i].tail->ancestor = leveled_lists[i + 1].tail;
      }
    }
  }

  int randomLevel() {
    int v = 0;
    while ((((double)rand() / RAND_MAX)) < 0.5 && abs(v) < maxLevel - 1) {

      v += 1;
    }
    return abs(v);
  }

  bool search(int target) { return leveled_lists[19].search(target); }

  void add(int num) {
    int level = randomLevel();
    QuadNode *inserted = leveled_lists[level].insert(num);
    for (int i = level - 1; i >= 0; i--) {
      inserted = leveled_lists[i].insert(num, inserted);
    }
  }

  bool erase(int num) { return leveled_lists[19].erase(num); }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
