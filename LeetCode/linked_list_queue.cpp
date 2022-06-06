#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};
struct LinkedQueue {
    Node *front, *rear;
    int len;
    LinkedQueue() {
        front = rear = nullptr;
        len = 0;
    }
    int size() {
        return len;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int data) {
        Node *node = new Node(data);
        node->data = data;
        node->next = nullptr;
        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = rear->next;
        }
        len++;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Q is empty" << endl;
            return -1;
        }
        Node *delNode = front;
        int ret = delNode->data;
        front = delNode->next;
        delete delNode;
        len--;
        return ret;
    }
};

int main () {
    LinkedQueue q;
    for (int i=1; i<=5; i++)
        q.enqueue(i);
    q.enqueue(10);
    while(!q.isEmpty()) {
        cout << q.dequeue() << endl;
    }
    return 0;
}
