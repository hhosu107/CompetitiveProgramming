#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *l, *r;
  Node(int data) {
    this->data = data;
    l = r = NULL;
  }
};

void bintree_left_dfs(Node *root, int &left_len, int depth,
                      vector<int> &left_view) {
  if (root == NULL)
    return;
  if (depth == left_len) {
    left_view.push_back(root->data);
    left_len++;
  }
  bintree_left_dfs(root->l, left_len, depth + 1, left_view);
  bintree_left_dfs(root->r, left_len, depth + 1, left_view);
}
