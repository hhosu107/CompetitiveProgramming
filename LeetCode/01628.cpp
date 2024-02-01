/* Polymorphism......
 * 1) Follow the ancestor's type (including 'const' itself).
 * 2) Remove 'virtual' when implement.
 * 3) For constructors, use parent node's class to represent childs, not the
 * implementing class itself (since every definition outside the class will be
 * done with 'Node *'.
 * Fuck C++.
 */

/*
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
protected:
  // define your fields here
public:
  virtual ~Node(){};
  virtual int evaluate() const = 0;
};

class Treenode : public Node {
public:
  int node_val;
  char op;
  Node *left, *right;
  ~Treenode() {
    if (left != nullptr)
      delete left;
    if (right != nullptr)
      delete right;
  }
  Treenode() { node_val = 0, op = 'N', left = nullptr, right = nullptr; }
  Treenode(int val) {
    node_val = val, op = 'N', left = nullptr, right = nullptr;
  }
  Treenode(char o, Node *l, Node *r) {
    node_val = 0, op = o, left = l, right = r;
  }
  int evaluate() const {
    if (op == 'N')
      return node_val;
    int lval = left->evaluate();
    int rval = right->evaluate();
    switch (op) {
    case '+':
      return lval + rval;
    case '-':
      return lval - rval;
    case '*':
      return lval * rval;
    case '/':
      return lval / rval;
    default:
      return node_val;
    }
  }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
  Node *buildTree(vector<string> &postfix) {
    stack<Node *> nodes;
    for (string p : postfix) {
      char tok = p[0];
      if ('0' <= tok && tok <= '9') {
        int val = stoi(p);
        Node *node = new Treenode(val);
        nodes.push(node);
      } else {
        Node *right = nodes.top();
        nodes.pop();
        Node *left = nodes.top();
        nodes.pop();
        Node *op_node = new Treenode(tok, left, right);
        nodes.push(op_node);
      }
    }
    Node *root = nodes.top();
    nodes.pop();
    return root;
  }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
