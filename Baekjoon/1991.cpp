#include<iostream>
#include<vector>
using namespace std;

struct bin_node {
  int left;
  int right;
  bin_node() : left(-1), right(-1) {}
  bin_node(int l, int r) : left(l), right(r) {}
  bin_node& operator=(const bin_node& other) {
    left = other.left;
    right = other.right;
    return *this;
  }
};

void preorder(vector<bin_node> &tree, int head) {
  if (head == -1) return;
  cout << (char)(head + 'A');
  preorder(tree, tree[head].left);
  preorder(tree, tree[head].right);
}

void inorder(vector<bin_node> &tree, int head) {
  if (head == -1) return;
  inorder(tree, tree[head].left);
  cout << (char)(head + 'A');
  inorder(tree, tree[head].right);
}

void postorder(vector<bin_node> &tree, int head) {
  if (head == -1) return;
  postorder(tree, tree[head].left);
  postorder(tree, tree[head].right);
  cout << (char)(head + 'A');
}

int main () {
  int n;
  cin >> n;
  char root, left, right;
  vector<bin_node> tree(n);
  for(int i=0; i<n; i++) {
    cin >> root >> left >> right;
    if (left != '.') tree[root-'A'].left = left - 'A'; else tree[root-'A'].left = -1;
    if (right != '.') tree[root-'A'].right = right - 'A'; else tree[root-'A'].right = -1;
  }
  preorder(tree, 0); cout << '\n';
  inorder(tree, 0); cout << '\n';
  postorder(tree, 0); cout << '\n';
  return 0;
}
