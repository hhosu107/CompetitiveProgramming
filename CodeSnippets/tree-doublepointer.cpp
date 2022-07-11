#include<iostream>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int v) : val(v), left(nullptr), right(nullptr) {}
  Node(int v, Node *l, Node *r) : val(v), left(l), right(r) {}
};
class Tree {
  public:
    Node *root;
    Tree() {

    }
    Tree(Node *r) {
      this->root = r;
    }
    void addNode (int value, Node **p);
};

void Tree::addNode(int value, Node **p) {
  if ((*p) == nullptr) {
    (*p) = new Node(value);
  } else {
    if (value < (*p)->val) {
      addNode(value, &((*p)->left));
    } else {
      addNode(value, &((*p)->right));
    }
  }
}

void preorder_print(Node *root) {
  if (root == nullptr) return;
  cout << root->val << endl;
  preorder_print(root->left);
  preorder_print(root->right);
}

void preorder_print(Tree *root) {
  if (root == nullptr) return;
  preorder_print(root->root);
}

int main () {
  Tree *tree = new Tree();
  tree->addNode(5, &(tree->root));
  tree->addNode(4, &(tree->root));
  tree->addNode(3, &(tree->root));
  tree->addNode(11, &(tree->root));
  tree->addNode(9, &(tree->root));
  preorder_print(tree);
  return 0;
}
