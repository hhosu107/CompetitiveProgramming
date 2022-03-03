#include<bits/stdc++.h>
using namespace std;
struct node{
  int e;
  node* l;
  node* r;
  node (int x): e(x), l(nullptr), r(nullptr){}
  node (int x, node* l, node* r): e(x), l(l), r(r){}
  node (int x, node* l, nullptr_t r): e(x), l(l), r(nullptr){}
  node (int x, nullptr_t l, node* r): e(x), l(nullptr), r(r){}
};

vector<int> v;
node* bin_tree(int left, int right) {
  if (left == right) {
    return new node(v[left]);
  } else {
    if (v[left + 1] > v[left])
      return new node(v[left], nullptr, bin_tree(left + 1, right));
    for(int i=left + 1; i <= right; i++) {
      if (v[i] > v[left]) {
        return new node(v[left], bin_tree(left + 1, i - 1), bin_tree(i, right));
      }
    }
    return new node(v[left], bin_tree(left + 1, right), nullptr);
  }
}

void preorder_print(node* root) {
  if (root == nullptr) return;
  preorder_print(root->l);
  preorder_print(root->r);
  cout << root->e << '\n';
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  while(cin >> n) {
    v.push_back(n);
  }
  node* root = bin_tree(0, v.size() - 1);
  preorder_print(root);
  return 0;
}
