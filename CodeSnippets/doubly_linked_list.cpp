#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename V>
class LinkedListNode {
  public:
    LinkedListNode<V> *next, *prev, *last;
    V data;
    LinkedListNode(V d, LinkedListNode<V> *n, LinkedListNode<V> *p) {
      data = d;
      setNext(n);
      setPrev(p);
    }
    LinkedListNode(V d) {
      data = d;
    }
    LinkedListNode() {}
    void setNext(LinkedListNode<V> *n) {
      next = n;
      if (this == last) {
        last = n;
      }
      if (n != nullptr && n->prev != this) {
        n->setPrev(this);
      }
    }
    void setPrev(LinkedListNode<V> *p) {
      prev = p;
      if (p != nullptr && prev->next != this) {
        p->setNext(this);
      }
    }
    LinkedListNode<V>* clone() {
      LinkedListNode<V> *next2 = nullptr;
      if (next != nullptr) {
        next2 = next->clone();
      }
      LinkedListNode<V> *head2 = new LinkedListNode(data, next2, nullptr);
      return head2;
    }
};

int main () {
  LinkedListNode<int> *root = new LinkedListNode<int>(2022);
  LinkedListNode<int> *root2 = new LinkedListNode<int>(2023);
  LinkedListNode<int> *root3 = new LinkedListNode<int>(2024);
  LinkedListNode<int> *root4 = new LinkedListNode<int>(2025);
  root->setNext(root3);
  root4->setNext(root2);
  root3->setNext(root4);
  LinkedListNode<int> *copyroot3 = root3->clone();
  for (LinkedListNode<int> *it=root; it != nullptr; it=it->next) {
    cout << it->data << " ";
  }
  cout << endl;
  for (LinkedListNode<int> *it=copyroot3; it != nullptr; it=it->next) {
    cout << it->data << " ";
  }
  cout << endl;
  for (LinkedListNode<int> *it=root2; it != nullptr; it=it->prev) {
    cout << it->data << " ";
  }
  cout << endl;
  return 0;
}

