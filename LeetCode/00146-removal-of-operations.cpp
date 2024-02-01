struct DoublyNode {
  int key;
  int val;
  DoublyNode *prev;
  DoublyNode *next;
  DoublyNode(int key, int val)
      : key(key), val(val), prev(nullptr), next(nullptr) {}
  DoublyNode(int key, int val, DoublyNode *prev, DoublyNode *next)
      : key(key), val(val), prev(prev), next(next) {}
};

class LRUCache {
public:
  unordered_map<int, DoublyNode *> cells;
  DoublyNode *dummy_head;
  DoublyNode *dummy_tail;
  int cap, maxcap;
  LRUCache(int capacity) {
    cells = unordered_map<int, DoublyNode *>();
    dummy_head = new DoublyNode(-1, -1);
    dummy_tail = new DoublyNode(-1, -1);
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
    cap = 0;
    maxcap = capacity;
  }

  bool exists(int key) { return cells.find(key) != cells.end(); }

  DoublyNode *remove(int key) {
    DoublyNode *removed = cells[key];
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    cells.erase(key);
    cap -= 1;
    return removed;
  }

  void put(DoublyNode *node) {
    node->prev = dummy_head;
    node->next = dummy_head->next;
    dummy_head->next->prev = node;
    dummy_head->next = node;
    cells[node->key] = node;
    cap += 1;
  }

  int get(int key) {
    if (!exists(key))
      return -1;
    DoublyNode *removed = remove(key);
    put(removed);
    return removed->val;
  }

  void put(int key, int value) {
    if (exists(key)) {
      DoublyNode *existing_node = remove(key);
      existing_node->val = value;
      put(existing_node);
    } else {

      if (cap == maxcap) {
        // remove the oldest
        DoublyNode *oldest = dummy_tail->prev;
        remove(oldest->key);
      }
      DoublyNode *curr = new DoublyNode(key, value);
      put(curr);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
