class DoubleListNode {
public:
    int key;
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, DoubleListNode*> nodeMap;
    int capacity;
    DoubleListNode* head;
    DoubleListNode* tail;
    LRUCache(int capacity) {
        nodeMap = unordered_map<int, DoubleListNode*>();
        this->capacity = capacity;
        head = new DoubleListNode(0, 0);
        tail = new DoubleListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(DoubleListNode* node) {
        // find node's prev/next and connect them + remove node from the nodeMap.
        node->prev->next = node->next;
        node->next->prev = node->prev;
        nodeMap.erase(node->key);
    }
    
    void insertToHead(DoubleListNode* node) {
        // insert at head's next, and point head's next's prev to the node.
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        nodeMap[node->key] = node;
    }
    
    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        DoubleListNode* node = nodeMap[key];
        removeNode(node);
        insertToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        DoubleListNode* new_node = new DoubleListNode(key, value);
        if (nodeMap.count(key) != 0) {
            DoubleListNode* old_node = nodeMap[key];
            removeNode(old_node);
        } else {
            if (nodeMap.size() >= capacity) {
                DoubleListNode* tail_node = tail->prev;
                removeNode(tail_node);
            }
        }
        // putting new node will be done here.
        insertToHead(new_node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
