/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        vector<Node*> copied_nodes;
        Node *tracker = head;
        unordered_map<Node*, int> node_idx;
        int node_cnt = 0;
        while(tracker != nullptr) {
            Node* new_node = new Node(tracker->val);
            copied_nodes.push_back(new_node);
            if (copied_nodes.size() >= 2) {
                copied_nodes[copied_nodes.size() - 2]->next = copied_nodes[copied_nodes.size() - 1];
            }
            node_idx[tracker] = node_cnt;
            tracker = tracker->next;
            node_cnt += 1;
        }
        int tracker_cnt = 0;
        Node *new_tracker = head;
        while(tracker_cnt < node_cnt) {
            if (node_idx.find(new_tracker->random) != node_idx.end()) {
                copied_nodes[tracker_cnt]->random = copied_nodes[node_idx[new_tracker->random]];
            }
            tracker_cnt += 1;
            new_tracker = new_tracker->next;
        }
        return copied_nodes[0];
    }
};
